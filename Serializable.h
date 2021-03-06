#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <fstream>
#include <iostream>

#include "Constants.h"

using namespace std;

namespace raytracing {
  
  class Serializable {
  private:
    static ofstream *outfile;
    static ifstream *infile;
  public:
    void openOutfile(const string &path){ 
      if (outfile != nullptr) if (outfile->is_open()) outfile->close();
      
      if (outfile == nullptr) 
	outfile = new std::ofstream (path, std::ofstream::out);
      else
	outfile->open(path, std::ofstream::out);
      
      if (outfile->bad())
	throw "Serialize::openOutfile: Unable to open outputfile " + path;
    }
    void openInfile(const string &path){ 
      if (infile == nullptr) 
	infile = new std::ifstream (path, std::ifstream::in);
      else
	throw "Multiple inputfiles not possible";
      if (infile->bad())
	throw "Serialize::openInfile: Unable to open inputfile " + path;
    }
    void writeIdentifier(const string &id, const string &indent="");
    void beginObject();
    void endObject(const string &indent="");
    void beginList();
    void endList(const string &indent="");
    void writePair(const string &id, const string &value, const string &indent="", bool lastPair = false);
    void writePair(const string &id, const double &value, const string &indent="", bool lastPair = false);
    void writeListDelimiter();
    string readIdentifier();
    virtual void serialize(const string &indent = "") = 0;
    virtual void deserialize() = 0;
    virtual const string type(){ return "Serializable"; } // type information is needed for serialization of arrays of objects
    void expectObjectBegin();
    void expectListBegin();
    double readDouble();
  };
}

#endif
 
