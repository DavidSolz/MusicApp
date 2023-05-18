/**
 * Project Untitled
 */


#ifndef _FILEHANDLERUNIX_H
#define _FILEHANDLERUNIX_H

#include "IFileHandler.h"


class FileHandlerUNIX: public IFileHandler {
public: 
    
/**
 * @param track
 */
char Read(track track );
    
/**
 * @param playlist
 */
char Read(Playlist playlist);
    
/**
 * @param path
 */
char Read(string path);
};

#endif //_FILEHANDLERUNIX_H