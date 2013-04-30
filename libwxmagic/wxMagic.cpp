/**
 *  @file   :   wxMagic.cpp
 *  @author :   Michael Uman
 *  @date   :   April 28, 2013
 */

#include <wx/wx.h>
#include <wx/dynlib.h>
#include "magic.h"
#include "wxMagic.h"

wxMagic::wxMagic()
:   m_bLoaded(false),
    _magic_open(0L),
    _magic_close(0L),
    _magic_load(0L),
    _magic_file(0L),
    m_dynLib(0L)
{
    // ctor
    if (OpenLibrary()) {
        if ((m_magic = _magic_open(MAGIC_MIME_TYPE)) == NULL) {
            fprintf(stderr, "ERROR: magic_open() error...\n");
            CloseLibrary();
        } else {
            if (_magic_load( m_magic, NULL ) == -1) {
                fprintf(stderr, "ERROR: magic_load() error...\n");
                CloseLibrary();
            } else {
                printf("loaded!\n");
            }
        }
    }
}

wxMagic::~wxMagic()
{
    // dtor
    if (m_bLoaded) {
        _magic_close(m_magic);
    }
    CloseLibrary();
}

/**
 *
 */

bool wxMagic::OpenLibrary()
{
    bool                bRes = false,
                        res = false;

    m_dynLib = new wxDynamicLibrary( wxT("libmagic.so") );

    if (m_dynLib->IsLoaded()) {
        _magic_open  = (__magic_open)m_dynLib->GetSymbol( wxT("magic_open"), &res);
        _magic_close = (__magic_close)m_dynLib->GetSymbol( wxT("magic_close"), &res);
        _magic_load  = (__magic_load)m_dynLib->GetSymbol( wxT("magic_load"), &res);
        _magic_file  = (__magic_file)m_dynLib->GetSymbol( wxT("magic_file"), &res);

        m_bLoaded = bRes = true;
    } else {
        delete m_dynLib;
        m_dynLib = 0L;
        fprintf(stderr, "ERROR: Unable to load dynamic library!\n");
    }

//    delete dynLib;

    return bRes;
}

void wxMagic::CloseLibrary()
{
    if (m_dynLib != 0L) {
        m_dynLib->Unload();
        delete m_dynLib;
        m_dynLib  = 0L;
        m_bLoaded = false;
    }

    return;
}

bool wxMagic::IsValid()
{
    return m_bLoaded;
}
