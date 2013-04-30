#include <wx/wx.h>
#include "wxMagic.h"

int main()
{
    wxMagic     magic;

    if (magic.IsValid()) {
        printf("Library is opened!\n");
    }
//    cout << "Hello world!" << endl;

    return 0;
}
