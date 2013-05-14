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
        wxString sMimeType;
//        wxString sTmp = fname.GetFullPath();
//        wxPrintf("sTmp %s\n", sTmp.c_str());
        magic.GetFileMimeType( fname.GetFullPath(), sMimeType );
        wxPrintf("%-48.48s %s\n", sFilename.c_str(), sMimeType.c_str());
        cont = dir.GetNext( &sFilename );
    }

    return 0;
}
