#include <wx/wx.h>
#include "wxMagic.h"

int main()
{
    wxMagic     magic;

    if (magic.IsValid()) {
        wxString sFileType, sMimeType;

        printf("Library is opened!\n");

        if (magic.GetFileType(wxT("test.jpg"), sFileType)) {
            printf("File type = %s\n", sFileType.c_str());
        }
        if (magic.GetFileMimeType(wxT("test.jpg"), sMimeType)) {
            printf("MIME type = %s\n", sMimeType.c_str());
        }
    }

    return 0;
}
