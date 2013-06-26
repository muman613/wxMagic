/*
    wxMagic - Magic file identification for wxWidgets
    Copyright (C) 2013  Michael A. Uman

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 *  @file       main.cpp
 *  @author :   Michael Uman
 *  @date   :   June 26, 2013
 */

#include <stdio.h>
#include <wx/wx.h>
#include <wx/dir.h>
#include <wx/filename.h>
#include "wxMagic.h"

int main(int argc, const char* argv[])
{
    wxString        sDirectory,
                    sFilename;
    wxMagic         magic;

    if (argc != 2) {
        fprintf(stderr, "%s <directory>\n", argv[0]);
        return -1;
    }

    sDirectory = argv[1];

    wxDir       dir(sDirectory);
    bool        cont;

    cont = dir.GetFirst( &sFilename, wxEmptyString, wxDIR_FILES );

    while (cont) {
        wxFileName  fname(argv[1], sFilename);
        wxString sMimeType, sFileType;
//        wxString sTmp = fname.GetFullPath();
//        wxPrintf("sTmp %s\n", sTmp.c_str());
        magic.GetFileType( fname.GetFullPath(), sFileType );
        magic.GetFileMimeType( fname.GetFullPath(), sMimeType );
        wxPrintf("%-40.40s %-32.32s %-40.40s\n", sFilename.c_str(), 
                                              sMimeType.c_str(),
                                              sFileType.c_str());
        cont = dir.GetNext( &sFilename );
    }

    return 0;
}
