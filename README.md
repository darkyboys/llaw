# 💬 LLAW
`LLAW` stands for `Open Local Linux Ai Wrapper Around Llama.cpp` which provides you all the environments for launching any `GGUF` Model with highly customisable personality. `LLAW` Is under MIT License and is completely Open Source and just provides a powerfull , Light Weight Runtime Environment for the `LLAMA.cpp` as UI using it's own `gtk3` and `webkit2gtk` powered `HTMLUI` Modded library, Meaning no server is hosted , The UI Directly talks to the backend.

## Privacy
`LLAW` has very very strict privacy polocies to protect your privacy all the time:-
 - No Built-In Telemetery.
 - No Internet Access.
 - No File Access except for the `~/.config/llaw/`.
 - Completely Open Source & Free To Mod and Use and even Re-distribute.
 - All Chats are stored in the RAM means once `LLAW` closes , No chat can be backed up.

## Project Structure
`LLAW` Project's source code is seperated into 3 main containers, Which all uses the `Cook` Build System by darkyboys at github so in order to build it you must have the `Cook` build system already installed. Because the project is mainly seperared into.
 - Core
 - Ui
 - Resolution

 - `Core`: This is pure C++ program which defines all the rule to talk to the `UI`.
 - `Ui`  : This is half `C++` and half `HTML`, `CSS`, `JAVASCRIPT` because the user interface is written in the `HTML`, `CSS` and `JAVASCRIPT` and is later compiled into the `CASCI` encoding to avoid the `C++ Header` syntax issues and then a `C++ Header` is generated for the `Core` to use which implements the `Ui` from the `CASCI` data which means the compiled `Ui` is in the form of numbers not raw `HTML`, `CSS` and `JAVASCRIPT`.
 - `Resolution`: This part installs all the dependencies of the `LLAW` project which is just the `Compiled LLAMA.CPP` Which `LLAW` maintains itself and the `Pre-Packaged` Libraries which you don't have to install as they comes with the Project. Including `HELL6.99MOCC`, `CASCI`, `HTMLUI`, `LINUXTOOLS`.

## Installing
`LLAW` Installation is straight-forward just to make sure that you have `git`, `gtk3`, `webkit2gtk` and `Cook` Build system by darkyboys installed.
If Yes then follow these commands:
```bash
git clone https://github.com/darkyboys/llaw
cd llaw
cook resolve
cook llaw-ui
cook
cook exec
mv bin ~/Documents/llaw
```

If you already have a gguf model then wait when the `LLAW` Opens when it will open with those commands then go to settings and on the model path change `../model/model.gguf` to the path your model is installed and click `save` but in case you don't have any model then launch the `cook resolve/model` command it will autoinstall the model according to default settings but remember as it installs the `llama 7B_Q5_0` which is rougly around `5 GB` So you must have a good internet which can keep it up.

In Case you do not have any of the dependencies then use these commands only if you are on `Arch Linux` or `Arch Linux` based Operating System.
```bash
sudo pacman -Syu
sudo pacman -S gtk3 webkit2gtk git
mkdir -p ~/.temp-llaw
cd ~/.temp-llaw
git clone https://github.com/darkyboys/cook
cd cook
mkdir bin
g++ src/cook.cc -o bin/cook
sudo bin/cook install
cd ..
git clone https://github.com/darkyboys/llaw
cd llaw
cook resolve
cook resolve/model
cook llaw-ui
cook
cook exec
mv model ~/Documents
mv bin ~/Documents/llaw
cd ~
rm -rf .temp-llaw
```

These commands will consume soo much internet but they will eventually correctly install the fully working base of `LLAW` in your system and to launch it you will need to open the `Documents` and you will see a new directory called `LLAW` there just open that and you will find a lots of binaries there but there will be one named `llaw` just launch it and you will be fine.


## Contributing ?
Feel free to fork / Modify and pull request.

# Thanks for reading
Written by ghgltggamer at 11:32AM IST on 7/26/25