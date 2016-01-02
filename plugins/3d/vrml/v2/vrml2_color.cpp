/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2016 Cirilo Bernardo <cirilo.bernardo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */


#include <iostream>

#include "vrml2_base.h"
#include "vrml2_color.h"


WRL2COLOR::WRL2COLOR() : WRL2NODE()
{
    m_Type = WRL2_COLOR;
    return;
}


WRL2COLOR::WRL2COLOR( WRL2NODE* aParent ) : WRL2NODE()
{
    m_Type = WRL2_COLOR;
    m_Parent = aParent;

    if( NULL != m_Parent )
        m_Parent->AddChildNode( this );

    return;
}


WRL2COLOR::~WRL2COLOR()
{
    #ifdef DEBUG
    std::cerr << " * [INFO] Destroying Color node\n";
    #endif
    return;
}


bool WRL2COLOR::isDangling( void )
{
    // this node is dangling unless it has a parent of type WRL2_INDEXEDFACESET

    if( NULL == m_Parent || m_Parent->GetNodeType() != WRL2_INDEXEDFACESET )
        return true;

    return false;
}


bool WRL2COLOR::AddRefNode( WRL2NODE* aNode )
{
    // this node may not own or reference any other node

    #ifdef DEBUG
    std::cerr << __FILE__ << ": " << __FUNCTION__ << ": " << __LINE__ << "\n";
    std::cerr << " * [BUG] AddRefNode is not applicable\n";
    #endif

    return false;
}


bool WRL2COLOR::AddChildNode( WRL2NODE* aNode )
{
    // this node may not own or reference any other node

    #ifdef DEBUG
    std::cerr << __FILE__ << ": " << __FUNCTION__ << ": " << __LINE__ << "\n";
    std::cerr << " * [BUG] AddChildNode is not applicable\n";
    #endif

    return false;
}


bool WRL2COLOR::Read( WRLPROC& proc, WRL2BASE* aTopNode )
{
    size_t line, column;
    proc.GetFilePosData( line, column );

    char tok = proc.Peek();

    if( proc.eof() )
    {
        #ifdef DEBUG
        std::cerr << __FILE__ << ": " << __FUNCTION__ << ": " << __LINE__ << "\n";
        std::cerr << " * [INFO] bad file format; unexpected eof at line ";
        std::cerr << line << ", column " << column << "\n";
        #endif
        return false;
    }

    if( '{' != tok )
    {
        #ifdef DEBUG
        std::cerr << proc.GetError() << "\n";
        std::cerr << __FILE__ << ": " << __FUNCTION__ << ": " << __LINE__ << "\n";
        std::cerr << " * [INFO] bad file format; expecting '{' but got '" << tok;
        std::cerr  << "' at line " << line << ", column " << column << "\n";
        #endif

        return false;
    }

    proc.Pop();
    std::string glob;

    if( proc.Peek() == '}' )
    {
        proc.Pop();
        return true;
    }

    if( !proc.ReadName( glob ) )
    {
        #ifdef DEBUG
        std::cerr << __FILE__ << ": " << __FUNCTION__ << ": " << __LINE__ << "\n";
        std::cerr << proc.GetError() <<  "\n";
        #endif

        return false;
    }

    proc.GetFilePosData( line, column );

    // expecting 'color'
    if( !glob.compare( "color" ) )
    {
        if( !proc.ReadMFVec3f( colors ) )
        {
            #ifdef DEBUG
            std::cerr << __FILE__ << ": " << __FUNCTION__ << ": " << __LINE__ << "\n";
            std::cerr << " * [INFO] invalid color set at line " << line << ", column ";
            std::cerr << column << "\n";
            std::cerr << " * [INFO] file: '" << proc.GetFileName() << "'\n";
            std::cerr << " * [INFO] message: '" << proc.GetError() << "'\n";
            #endif
            return false;
        }
    }
    else
    {
        #ifdef DEBUG
        std::cerr << __FILE__ << ": " << __FUNCTION__ << ": " << __LINE__ << "\n";
        std::cerr << " * [INFO] bad Color at line " << line << ", column ";
        std::cerr << column << "\n";
        std::cerr << " * [INFO] file: '" << proc.GetFileName() << "'\n";
        #endif

        return false;
    }

    if( proc.Peek() == '}' )
    {
        proc.Pop();
        return true;
    }

    proc.GetFilePosData( line, column );

    #ifdef DEBUG
    std::cerr << __FILE__ << ": " << __FUNCTION__ << ": " << __LINE__ << "\n";
    std::cerr << " * [INFO] bad Color at line " << line << ", column ";
    std::cerr << column << " (no closing brace)\n";
    std::cerr << " * [INFO] file: '" << proc.GetFileName() << "'\n";
    #endif

    return false;
}


SGNODE* WRL2COLOR::TranslateToSG( SGNODE* aParent, bool calcNormals )
{
    // XXX - TO IMPLEMENT
    return NULL;
}
