/**
 *  @file       main.cpp
 */

#include <wx/wx.h>
#include "wxMagic.h"

int main(int argc, const char* argv[])
{
    wxMagic     magic;

    if (argc < 2) {
        fprintf(stderr, "%s [files]\n",argv[0]);
        return -1;
    }

    if (magic.IsValid()) {
        wxString sFileType, sMimeType;

        for (int i = 1 ; i < argc ; i++) {
            if (magic.GetFileType( argv[i], sFileType)) {
                printf("%s : %s\n", argv[i], sFileType.c_str());
            }
        }
    }

    return 0;
}
