#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <fstream>
#include <iostream>

using namespace std;

namespace raytracing {
  
  class Serializable {
  private:
    static ofstream *outfile;
    static ifstream *infile;
  public:
    void openOutfile(const string &path){ 
      if (outfile == nullptr) 
	outfile = new std::ofstream (path, std::ofstream::out);
      else
	throw "Multiple outputfiles not possible";
    }
    void openInfile(const string &path){ 
      if (infile == nullptr) 
	infile = new std::ifstream (path, std::ifstream::in);
      else
	throw "Multiple inputfiles not possible";
    }
    void writeIdentifier(const string &id, const string &indent="");
    void beginObject();
    void endObject(const string &indent="");
    void writePair(const string &id, const string &value, const string &indent="", bool lastPair = false);
    void writePair(const string &id, const double &value, const string &indent="", bool lastPair = false);
    string readIdentifier();
    virtual void serialize(const string &indent = "") = 0;
    virtual void deserialize() = 0;
    void expectObjectBegin();
    double readDouble();
  };
}

#endif
 
