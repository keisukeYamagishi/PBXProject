#include <string>
#include <stdio.h>

#define OPTION_OUTPUT "output"
#define OPTION_OVERWIRTE "overwirte"
#define OPTION_VERSION "version"
#define OPTION_ADDFILE "addfile"


class option {
public:
	struct options {
		std::string output;
        std::string overwrite;
        std::string version;
        std::string addFile;
   };
   option();
   struct options option_s;
   void setOption(int argc, const char *argv[]);
};