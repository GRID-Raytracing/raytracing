#include "Serializable.h" 

namespace raytracing {
    
    ofstream* Serializable::outfile = nullptr;
    ifstream* Serializable::infile = nullptr;
  
    void Serializable::writeIdentifier(const string &id, const string &indent){
      *outfile << indent << id << ": ";
    }
    void Serializable::beginObject(){
      *outfile << "{" << endl;
    }
    void Serializable::endObject(const string &indent){
      *outfile << indent << "}" << endl;
    }
    void Serializable::beginList(){
      *outfile << "[" << endl;
    }
    void Serializable::endList(const string &indent){
      *outfile << indent << "]" << endl;
    }
    void Serializable::writeListDelimiter(){
      *outfile << "," << endl;
    }
    void Serializable::writePair(const string &id, const string &value, const string &indent, bool lastPair){
//      cerr << "String" << endl;
       *outfile << indent << id << ": " << value << (lastPair?"":",") << endl;
    }
    void Serializable::writePair(const string &id, const double &value, const string &indent, bool lastPair){
//      writePair(id, string(value), indent, endOfObject);
//      cerr << "Double" << endl;
       *outfile << indent << id << ": " << value << (lastPair?"":",") << endl;
     }
     string Serializable::readIdentifier(){
       char c;
       string s;
       do {
         infile->get(c);
         if (infile->bad()) 
	   return s;
	 
         switch (c){
	   case '\n': break;
	   case ' ': break;
	   case ':': return s;
	   case ']': if (s.compare("") == 0){ s+=c; return s; } else throw "] without newline";
	   case '}': if (s.compare("") == 0){ s+=c; return s; } else throw "} without newline";
	   default:
	     s+=c;
	     break;
	 }
	     
      } while (true);
   }
   void Serializable::expectObjectBegin(){
       char c;
       do {
         infile->get(c);
         if (infile->bad()) 
	   throw "Missing {";
	 
         switch (c){
	   case '\n': break;
	   case ' ': break;
	   case '{': return;
	   default:
	     throw "Looking for {, found " + c;
	 }
      } while (true);
   }
   void Serializable::expectListBegin(){
       char c;
       do {
         infile->get(c);
         if (infile->bad()) 
	   throw "Missing [";
	 
         switch (c){
	   case '\n': break;
	   case ' ': break;
	   case '[': return;
	   default:
	     throw "Looking for [, found " + c;
	 }
      } while (true);
   }
   double Serializable::readDouble(){
       char c;
       string s;
       do {
         infile->get(c);
         if (infile->bad()) 
	   throw "Failing to read Double";
	 
         switch (c){
	   case '\n': if (s.length() == 0) break; else return atof(s.c_str());
	   case ' ': if (s.length() == 0) break; else return atof(s.c_str());;
	   case '0': s+=c; break;
	   case '1': s+=c; break;
	   case '2': s+=c; break;
	   case '3': s+=c; break;
	   case '4': s+=c; break;
	   case '5': s+=c; break;
	   case '6': s+=c; break;
	   case '7': s+=c; break;
	   case '8': s+=c; break;
	   case '9': s+=c; break;
	   case '.': s+=c; break;
	   case '-': s+=c; break;
	   case ',': return atof(s.c_str());
	   default:
	     throw "Failing to read double, found " + c;
	 }
      } while (true);
   }
}










