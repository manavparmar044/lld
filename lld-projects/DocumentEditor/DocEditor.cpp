#include <iostream>
#include <vector>
#include <string>
#include<fstream>

using namespace std;

class DocumentElement{
    public:
    virtual string render() = 0;
};

class TextElement : public DocumentElement{
    private:
    string text;
    public:
    TextElement(string text){
        this->text = text;
    }

    string render() override{
        return text;
    }
};

class ImageElement : public DocumentElement{
    private:
    string imagePath;
    public:
    ImageElement(string imagePath){
        this->imagePath = imagePath;
    }

    string render() override{
        return "[Image: "+imagePath+ " ]";
    }
}; 

class NewLineElement : public DocumentElement{
    public:
    string render() override{
        return "\n";
    }
};

class TabElement : public DocumentElement{
    public:
    string render() override{
        return "\t";
    }
};

class Document{
    private:
    vector<DocumentElement*> documentElements;

    public:
    void addElement(DocumentElement *ele){
        documentElements.push_back(ele);
    }
    string render(){
        string res;
        for(int i = 0;i<documentElements.size();i++){
            res += documentElements[i]->render();
        }
        return res;
    }
};

class Persistence{
    public:
    virtual void save(string data) = 0;
};

class FileStorage : public Persistence{
    public:
    void save(string data) override{
        ofstream outFile("doc.txt");
        if(outFile){
            outFile << data;
            outFile.close();
            cout<<"Saved\n";
        }
        cout<<"Error\n";
    }
};

class DBStorage : public Persistence{
    public:
    void save(string data){
        // Logic/Query
    }
};

class DocumentEditor{
    private:
    Document *document;
    Persistence *storage;
    string renderedDocument;

    public:

    DocumentEditor(Document *document,Persistence *storage){
        this->document = document;
        this->storage = storage;
    }

    void addText(string text){
        document->addElement(new TextElement(text));
    }

    void addImage(string image){
        document->addElement(new ImageElement(image));
    }

    void addTab(){
        document->addElement(new TabElement());
    }

    void addNewLine(){
        document->addElement(new NewLineElement());
    }

    string renderDocument(){
        if(renderedDocument.empty()){
            renderedDocument = document->render();
        }
        return renderedDocument;
    }

    void saveDocument(){
        storage->save(renderDocument());
    }
};

int main(){

    Document *document = new Document();
    Persistence *persistence = new FileStorage();
    DocumentEditor *documentEditor  = new DocumentEditor(document,persistence);

    documentEditor->addText("Hello, world!");
    documentEditor->addNewLine();
    documentEditor->addText("This is a real-world document documentEditor example.");
    documentEditor->addNewLine();
    documentEditor->addTab();
    documentEditor->addText("Indented text after a tab space.");
    documentEditor->addNewLine();
    documentEditor->addImage("picture.jpg");

    return 0;
    
}