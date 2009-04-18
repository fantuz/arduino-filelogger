//
// CREDITS:
//
// DESCRIPTION:
// This Arduino library provides minimal functionallity to log data into a file in the
// root folder of a microSD memory card attached to Arduino.
//
// DISCLAIMER:
// The author is in no way responsible for any problems or damage caused by
// using this code. Use at your own risk.
//
// LICENSE:
// This code is distributed under the GNU Public License
// which can be found at http://www.gnu.org/licenses/gpl.txt
//

#include "mmc.h"
#include "nanofat.h"
#include <WProgram.h>

#ifndef FileLogger_h
#define FileLogger_h

class FileLogger {
  private:
  public:
  
	FileLogger(void);

	// append - appends a data buffer to the file
	int append(const char* filename, byte* buffer, unsigned long length);
};

extern FileLogger File_logger;

#endif

