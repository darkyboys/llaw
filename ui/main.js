const chat = document.getElementById("chat-window");
const input = document.getElementById("user-input");
const sendBtn = document.getElementById("send-button");

sendBtn.addEventListener("click", sendMessage);
input.addEventListener("keydown", e => {
  if (e.key === "Enter") sendMessage();
});

marked.setOptions({
  gfm: true,
  breaks: true,
  langPrefix: 'language-',
});

let currentBotMessage = null;
let currentUserMessage = "";
function sendMessage() {
  const userText = input.value.trim();
  if (!userText) return;
  appendMessage("user", userText);
  currentUserMessage = userText;
  input.value = "";
  blockInput();
  generateBotReply(userText); // Replace with actual backend call
}

function appendMessage(sender, text) {
  const safeText = typeof text === "string" ? text : String(text);

  if (sender === "user") {
    const container = document.createElement("div");
    container.className = "message-container user";

    const label = document.createElement("div");
    label.className = "message-label user-label";
    label.textContent = "You";

    const userMsg = document.createElement("button");
    userMsg.className = "message user";
    userMsg.textContent = escapeHTML(safeText);

    container.appendChild(label);
    container.appendChild(userMsg);
    chat.appendChild(container);
  }

  chat.scrollTop = chat.scrollHeight;
}


function writeResponse(markdownText) {
  if (!markdownText || markdownText.trim() === "") return;

  if (!currentBotMessage) {
    const container = document.createElement("div");
    container.className = "message-container bot";

    const label = document.createElement("div");
    label.className = "message-label bot-label";
    label.textContent = "AI";

    currentBotMessage = document.createElement("div");
    currentBotMessage.className = "message bot";

    container.appendChild(label);
    container.appendChild(currentBotMessage);
    chat.appendChild(container);
  }

  currentBotMessage.innerHTML = marked.parse(markdownText);
  addCopyButtons(currentBotMessage);
  chat.scrollTop = chat.scrollHeight;
}



function blockInput() {
  input.disabled = true;
  input.style.opacity = "0.6";
}

function freeInput() {
  input.disabled = false;
  input.style.opacity = "1";
  input.focus();
  currentBotMessage = null;
}

function escapeHTML(str) {
  return str.replace(/[&<>"']/g, m => ({
    '&': '&amp;',
    '<': '&lt;',
    '>': '&gt;',
    '"': '&quot;',
    "'": '&#39;'
  })[m]);
}

function addCopyButtons(container) {
  container.querySelectorAll("pre").forEach((pre) => {
    if (pre.dataset.copyButtonAdded === "true") return;
    pre.dataset.copyButtonAdded = "true";

    const button = document.createElement("button");
    button.textContent = "📋";
    button.className = "copy-btn";

    button.addEventListener("click", (e) => {
      e.stopPropagation();
      const code = pre.querySelector("code");
      const text = code ? code.innerText : pre.innerText;
      copyToClipboard(text, button, code || pre);
    });

    button.addEventListener("mousedown", e => e.stopPropagation());

    pre.style.position = "relative";
    pre.appendChild(button);
  });
}

function copyToClipboard(text, button, codeBlock) {
  if (navigator.clipboard && navigator.clipboard.writeText) {
    navigator.clipboard.writeText(text).then(() => {
      showCopySuccess(button);
    }).catch(() => {
      fallbackCopy(text, button, codeBlock);
    });
  } else {
    fallbackCopy(text, button, codeBlock);
  }
}

function fallbackCopy(text, button, codeBlock) {
  const textarea = document.createElement("textarea");
  textarea.value = text;
  textarea.style.position = "fixed";
  textarea.style.top = "-9999px";
  document.body.appendChild(textarea);
  textarea.focus();
  textarea.select();

  try {
    const successful = document.execCommand("copy");
    if (successful) {
      showCopySuccess(button);
    } else {
      throw new Error("execCommand failed");
    }
  } catch (err) {
    showCopyFail(button, codeBlock);
  }

  document.body.removeChild(textarea);
}

function showCopySuccess(button) {
  button.textContent = "✅";
  setTimeout(() => (button.textContent = "📋"), 1000);
}

function showCopyFail(button, codeBlock) {
  button.textContent = "❌";

  const range = document.createRange();
  range.selectNodeContents(codeBlock);
  const selection = window.getSelection();
  selection.removeAllRanges();
  selection.addRange(range);

  setTimeout(() => {
    button.textContent = "📋";
  }, 2000);
}

function init_backend (){
  let value = 0;
  if (typeof window.nativeBridge == 'object' && typeof window.nativeBridge.invoke == 'function'){
    value = 1;
  }
  return value;
}

function getResponse() {
  return currentBotMessage?.textContent || "";
}

// Simulated bot reply
// let can_fetch_response = false;
// function checkResponse(){
//   if (can_fetch_response){
//     let old_response = "";
//     setInterval (()=>{
//       if (getResponse() == old_response){
//         freeInput();
//         can_fetch_response = false;
//         // window.nativeBridge.invoke('AppendOnChatMemory', `[user]: ${currentUserMessage}, [ai]: ${currentBotMessage}.`)
//       }
//       else {
//         old_response = getResponse();
//       }
//     }, 2000);
//   }
// }


function generateBotReply(userText) {
  let step = 0;
  can_fetch_response = true;

  // checkResponse();

  // const responseParts = [
  //   "**Sure!** Here's a C++ snippet:\n\n```cpp\n",
  //   "#include <iostream>\n",
  //   "int main() {\n",
  //   "  std::cout << \"Hello!\";\n",
  //   "  return 0;\n",
  //   "}\n",
  //   "```"
  // ];

  // let fullText = "";

  // const streamInterval = setInterval(() => {
  //   if (step >= responseParts.length) {
  //     clearInterval(streamInterval);
  //     freeInput();
  //     return;
  //   }

  //   fullText += responseParts[step++];
  //   writeResponse(fullText);
  // }, 300);

  if (init_backend()){
    window.nativeBridge.invoke ('makeResponse', currentUserMessage);
  }
  else {
    alert ("The Backend didn't init");
  }
}


const openBtn = document.getElementById("open-settings");
const popup = document.getElementById("settings-popup");
const saveBtn = document.getElementById("save-settings");

openBtn.addEventListener("click", () => {
  popup.classList.remove("hidden");
});

saveBtn.addEventListener("click", () => {
  // const settings = {
  //   user_name: document.getElementById("user_name").value || "Annonymous",
  //   user_bio: document.getElementById("user_bio").value || "Annonymous",
  //   user_gender: document.getElementById("user_gender").value || "Annonymous",
  //   user_origin: document.getElementById("user_origin").value || "Annonymous",
  //   user_hobies: document.getElementById("user_hobies").value || "Annonymous",
  //   ai_type: document.getElementById("ai_type").value || "Casual",
  //   ai_gender: document.getElementById("ai_gender").value || "Female",
  //   ai_name: document.getElementById("ai_name").value || "Open Linux Local Ai",
  //   ai_aurhor: document.getElementById("ai_aurhor").value || "Author is unknown because it depends on the model",
  //   llaw_prompts: document.getElementById("llaw_prompts").value || "you are running on Open Linux Local Ai Wrapper Around Llama.cpp (LLAW) ..."
  // };

  if (document.getElementById("user_name").value != ""){
    window.nativeBridge.invoke("cfgSetUserName", document.getElementById("user_name").value.replaceAll ("`", ""));
  }
  if (document.getElementById("user_origin").value != ""){
    window.nativeBridge.invoke("cfgSetUserOrigin", document.getElementById("user_origin").value.replaceAll ("`", ""));
  }
  if (document.getElementById("user_hobies").value != ""){
    window.nativeBridge.invoke("cfgSetUserHobby", document.getElementById("user_hobies").value.replaceAll ("`", ""));
  }
  if (document.getElementById("user_bio").value != ""){
    window.nativeBridge.invoke("cfgSetUserBio", document.getElementById("user_bio").value.replaceAll ("`", ""));
  }
  if (document.getElementById("user_gender").value != ""){
    window.nativeBridge.invoke("cfgSetUserGender", document.getElementById("user_gender").value.replaceAll ("`", ""));
  }
  if (document.getElementById("ai_type").value != ""){
    window.nativeBridge.invoke("cfgSetAiType", document.getElementById("ai_type").value.replaceAll ("`", ""));
  }
  if (document.getElementById("ai_name").value != ""){
    window.nativeBridge.invoke("cfgSetAiName", document.getElementById("ai_name").value.replaceAll ("`", ""));
  }
  if (document.getElementById("ai_author").value != ""){
    window.nativeBridge.invoke("cfgSetAiAuthor", document.getElementById("ai_author").value.replaceAll ("`", ""));
  }
  if (document.getElementById("ai_gender").value != ""){
    window.nativeBridge.invoke("cfgSetAiGender", document.getElementById("ai_gender").value.replaceAll ("`", ""));
  }
  if (document.getElementById("model_path").value != ""){
    window.nativeBridge.invoke("cfgSetModelPath", document.getElementById("model_path").value.replaceAll ("`", ""));
  }
  if (document.getElementById("llaw_prompts").value != ""){
    window.nativeBridge.invoke("cfgSetLlawPrompts", document.getElementById("llaw_prompts").value.replaceAll ("`", ""));
  }

  window.nativeBridge.invoke("cfgWrite", "null");

  // console.log("🔧 Saved Settings:", settings);
  popup.classList.add("hidden");
});
