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
