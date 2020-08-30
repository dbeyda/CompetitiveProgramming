#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stdlib.h>

using namespace std;


class Directory;
class Entry;
class File;
class FileSystem;

class Entry
{
    public:
    string name;
    Directory* parent;

    Entry(string entryName, Directory* parent) : name(entryName), parent(parent) {};
};

class File : public Entry
{
    int size;
    string content;

    public:
    File(string name, string cont, Directory *parent) : Entry(name, parent), content(cont)
    {
        size = cont.size();
    }
    int getSize() { return size; }
    void printContent() { cout << content; }
    string getContent() { return content; }
    void setContent(string cnt) { content = cnt; };
};

class Directory : public Entry
{
    public:
    vector<File*> files;
    vector<Directory*> dirs;

    Directory(string name, Directory *parentDir) : Entry(name, parentDir) {}

    bool hasChilds()
    {
        return files.size() || dirs.size();
    }
    void listChilds()
    {
        for(auto& d : dirs)
            cout << "*dir* " << d->name << '\n';
        for(auto& f : files)
            cout << "*file* " << f->name << '\n';
    }
    void listDirs()
    {
        for(auto& d : dirs)
            cout << "*dir* " << d->name << '\n';
    }
    void listFiles()
    {
        for(auto& d : files)
            cout << "*file* " << d->name << '\n';
    }
    File* getFileByName(string fileName)
    {
        for(auto *f : files)
        {
            if (f->name == fileName)
                return f;
        }
        return nullptr;
    }
    void newFile(string name, string content)
    {
        File* file = new File(name, content, this);
        files.push_back(file);
    }
    void newDir(string name)
    {
        Directory* dir = new Directory(name, this);
        dirs.push_back(dir);
    }
    Directory* getDirByName(string name)
    {
        for(auto *d : dirs)
            if(d->name == name)
                return d;
        return nullptr;
    }
};

class FileSystem    // implemented as a singleton
{
    Directory* root;
    Directory* currentDir;
    string inputPrompt = "> ";
    static FileSystem* fs;

    public:
    static FileSystem* get()
    {
        if (!fs)
            fs = new FileSystem();
        return fs;
    }

    FileSystem()
    {
        root = new Directory("root", nullptr);
        currentDir = root;
    }

    string getPathString()
    {
        Directory *ptr = currentDir;
        string path = "";
        while(ptr)
        {
            path = '/' + ptr->name + path;
            ptr = ptr->parent;
        }
        return path;
    }

    void prompt(string str)
    {
        cout << str << '\n' << getPathString() << " " << inputPrompt;
    }

    void waitForInput()
    {
        string command;
        while(true)
        {
            prompt("Waiting command [newFile | readFile | newDir | cd | ls | shutdown]:");
            cin >> command;
            system("clear");
            if (command == "shutdown") break;
            else if (command == "newFile")
            {
                cout << "File name: ";
                string fileName;
                cin >> fileName;
                cout << "File content: ";
                string content;
                std::cin.ignore();
                std::getline(std::cin, content);
                currentDir->newFile(fileName, content);
                cout << "Added!\n";
            }
            else if (command == "ls")
            {
                if(currentDir->hasChilds())
                {
                    cout << "\n Entries in " << getPathString() << ":\n";
                    currentDir->listChilds();
                    cout << "\n";
                }
                else cout << "\nDirectory is empty.\n\n";
            }
            else if (command == "readFile")
            {
                if(currentDir->hasChilds())
                {
                    cout << "\n Entries in " << getPathString() << ":\n";
                    currentDir->listFiles();
                    cout << "\n";
                    cout << "File name: ";
                    string fileName;
                    cin >> fileName;
                    File* f = currentDir->getFileByName(fileName);
                    if (f)
                    {
                        cout << "\n\n** Contents of " << f->name << " **\n";
                        cout << "************************\n\n";
                        cout << f->getContent() << "\n\n";
                        cout << "************************\n\n";
                    }
                    else cout << "No such file in this directory.\n";
                }
                else cout << "\nDirectory is empty.\n\n";
            }
            else if (command == "newDir")
            {
                cout << "Dir name: ";
                string dirName;
                std::cin.ignore();
                std::getline(std::cin, dirName);
                currentDir->newDir(dirName);
                cout << "Added!\n";
            }
            else if (command == "cd")
            {
                cout << "\n Entries in " << getPathString() << ":\n";
                currentDir->listDirs();
                cout << "\n";
                cout << "Dir name: ";
                string dirName;
                std::cin.ignore();
                std::getline(std::cin, dirName);
                if (dirName == "..")
                {
                    if(currentDir->parent) currentDir = currentDir->parent;
                    else cout << "You are already at the root directory.\n";
                }
                else
                {
                    Directory* nextDir = currentDir->getDirByName(dirName);
                    if (nextDir) currentDir = nextDir;
                    else cout << "Directory not found.\n";
                }
            }
        }
    }
};

FileSystem* FileSystem::fs = nullptr;

int main()
{
    cout << "Starting...\n";
    FileSystem* fs = FileSystem::get();
    fs->waitForInput();
    return 0;
}
