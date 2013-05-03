#ifndef __WXMAGIC_H__
#define __WXMAGIC_H__

#include <wx/wx.h>
#include <wx/dynlib.h>
#include <magic.h>

typedef magic_t (*__magic_open)(int);
typedef void (*__magic_close)(magic_t);
typedef int (*__magic_load)(magic_t, const char *);

typedef const char* (*__magic_file)(magic_t, const char *);
typedef int (*__magic_setflags)(magic_t cookie, int flags);

class wxMagic {
public:
    wxMagic();
    virtual ~wxMagic();

    bool    IsValid();

    bool    GetFileType(wxString sFilename, wxString& sType);
    bool    GetFileMimeType(wxString sFilename, wxString& sMimeType);

protected:

    bool    OpenLibrary();
    void    CloseLibrary();

private:
    bool                m_bLoaded;
    magic_t             m_magic;

    __magic_open        _magic_open;
    __magic_close       _magic_close;
    __magic_load        _magic_load;
    __magic_file        _magic_file;
    __magic_setflags    _magic_setflags;

    wxDynamicLibrary*   m_dynLib;
};

#endif // __WXMAGIC_H__
