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
            if (magic.GetFileType( argv[i], sFileType )) {
#if wxCHECK_VERSION(2,9,4)
                wxPrintf("%s : %s\n", argv[i], sFileType.c_str());
#else
                printf("%s : %s\n", argv[i], sFileType.c_str());
#endif
            }
            if (magic.GetFileMimeType( argv[i], sMimeType )) {
#if wxCHECK_VERSION(2,9,4)
                wxPrintf("%s : %s\n", argv[i], sMimeType.c_str());
#else
                printf("%s : %s\n", argv[i], sMimeType.c_str());
#endif
            }
        }
    }

    return 0;
}
