	/**********************************************/
	/* EESchema - symbtext.cpp for Library Editor */
	/**********************************************/

/* Menu et routines de creation, modification, suppression de textes
	du type symbole
	(textes autres que Fields)
*/

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "symbtext.h"
#endif

#include "fctsys.h"
#include "gr_basic.h"

#include "common.h"
#include "program.h"
#include "libcmp.h"
#include "general.h"

#include "symbtext.h"

#include "protos.h"



/*!
 * WinEDA_bodytext_PropertiesFrame type definition
 */

IMPLEMENT_DYNAMIC_CLASS( WinEDA_bodytext_PropertiesFrame, wxDialog )

/*!
 * WinEDA_bodytext_PropertiesFrame event table definition
 */

BEGIN_EVENT_TABLE( WinEDA_bodytext_PropertiesFrame, wxDialog )

////@begin WinEDA_bodytext_PropertiesFrame event table entries
    EVT_BUTTON( wxID_OK, WinEDA_bodytext_PropertiesFrame::OnOkClick )

    EVT_BUTTON( wxID_CANCEL, WinEDA_bodytext_PropertiesFrame::OnCancelClick )

////@end WinEDA_bodytext_PropertiesFrame event table entries

END_EVENT_TABLE()

/*!
 * WinEDA_bodytext_PropertiesFrame constructors
 */

WinEDA_bodytext_PropertiesFrame::WinEDA_bodytext_PropertiesFrame( )
{
}

WinEDA_bodytext_PropertiesFrame::WinEDA_bodytext_PropertiesFrame( WinEDA_LibeditFrame* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
LibDrawText * CurrentText = (LibDrawText *) CurrentDrawItem;
wxString msg;

	m_Parent = parent;
    Create(parent, id, caption, pos, size, style);

	if ( CurrentText )
	{
		msg = ReturnStringFromValue(g_UnitMetric, CurrentText->m_Size.x, m_Parent->m_InternalUnits);
		m_Size->SetValue(msg);
		m_NewText->SetValue(CurrentText->m_Text);
		if ( CurrentText->m_Unit == 0 ) m_CommonUnit->SetValue(TRUE);
		if ( CurrentText->m_Convert == 0 ) m_CommonConvert->SetValue(TRUE);
		if ( CurrentText->m_Horiz == TEXT_ORIENT_VERT ) m_Orient->SetValue(TRUE);
	}
	else
	{
		msg = ReturnStringFromValue(g_UnitMetric, g_LastTextSize, m_Parent->m_InternalUnits);
		m_Size->SetValue(msg);
		if ( ! g_FlDrawSpecificUnit ) m_CommonUnit->SetValue(TRUE);
		if ( ! g_FlDrawSpecificConvert ) m_CommonConvert->SetValue(TRUE);
		if ( g_LastTextOrient == TEXT_ORIENT_VERT ) m_Orient->SetValue(TRUE);
	}

	msg = m_SizeText->GetLabel() + ReturnUnitSymbol();
	m_SizeText->SetLabel(msg);
}

/*!
 * WinEDA_bodytext_PropertiesFrame creator
 */

bool WinEDA_bodytext_PropertiesFrame::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin WinEDA_bodytext_PropertiesFrame member initialisation
    m_NewText = NULL;
    m_SizeText = NULL;
    m_Size = NULL;
    m_CommonUnit = NULL;
    m_CommonConvert = NULL;
    m_Orient = NULL;
    m_btClose = NULL;
////@end WinEDA_bodytext_PropertiesFrame member initialisation

////@begin WinEDA_bodytext_PropertiesFrame creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end WinEDA_bodytext_PropertiesFrame creation
    return true;
}

/*!
 * Control creation for WinEDA_bodytext_PropertiesFrame
 */

void WinEDA_bodytext_PropertiesFrame::CreateControls()
{
	SetFont(*g_DialogFont);

////@begin WinEDA_bodytext_PropertiesFrame content construction
    // Generated by DialogBlocks, 29/04/2008 21:08:05 (unregistered)

    WinEDA_bodytext_PropertiesFrame* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxStaticBox* itemStaticBoxSizer3Static = new wxStaticBox(itemDialog1, wxID_ANY, _(" Text : "));
    wxStaticBoxSizer* itemStaticBoxSizer3 = new wxStaticBoxSizer(itemStaticBoxSizer3Static, wxVERTICAL);
    itemBoxSizer2->Add(itemStaticBoxSizer3, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer3->Add(itemBoxSizer4, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer4->Add(itemBoxSizer5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText6 = new wxStaticText( itemDialog1, wxID_STATIC, _("Name:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer5->Add(itemStaticText6, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP|wxADJUST_MINSIZE, 5);

    m_NewText = new wxTextCtrl( itemDialog1, ID_TEXTCTRL, _T(""), wxDefaultPosition, wxSize(250, -1), 0 );
    itemBoxSizer5->Add(m_NewText, 0, wxALIGN_LEFT|wxALL, 5);

    wxBoxSizer* itemBoxSizer8 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer4->Add(itemBoxSizer8, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SizeText = new wxStaticText( itemDialog1, wxID_STATIC, _("Size:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer8->Add(m_SizeText, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP|wxADJUST_MINSIZE, 5);

    m_Size = new wxTextCtrl( itemDialog1, ID_TEXTCTRL1, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer8->Add(m_Size, 0, wxALIGN_LEFT|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer11Static = new wxStaticBox(itemDialog1, wxID_ANY, _(" Text Options : "));
    wxStaticBoxSizer* itemStaticBoxSizer11 = new wxStaticBoxSizer(itemStaticBoxSizer11Static, wxVERTICAL);
    itemStaticBoxSizer3->Add(itemStaticBoxSizer11, 0, wxALIGN_LEFT|wxALL, 5);

    m_CommonUnit = new wxCheckBox( itemDialog1, ID_CHECKBOX, _("Common to Units"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_CommonUnit->SetValue(false);
    itemStaticBoxSizer11->Add(m_CommonUnit, 0, wxALIGN_LEFT|wxALL, 5);

    m_CommonConvert = new wxCheckBox( itemDialog1, ID_CHECKBOX1, _("Common to convert"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_CommonConvert->SetValue(false);
    itemStaticBoxSizer11->Add(m_CommonConvert, 0, wxALIGN_LEFT|wxALL, 5);

    m_Orient = new wxCheckBox( itemDialog1, ID_CHECKBOX2, _("Vertical"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_Orient->SetValue(false);
    itemStaticBoxSizer11->Add(m_Orient, 0, wxALIGN_LEFT|wxALL, 5);

    wxBoxSizer* itemBoxSizer15 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer2->Add(itemBoxSizer15, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton16 = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton16->SetDefault();
    itemButton16->SetForegroundColour(wxColour(206, 0, 0));
    itemBoxSizer15->Add(itemButton16, 0, wxGROW|wxALL, 5);

    m_btClose = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    m_btClose->SetForegroundColour(wxColour(0, 0, 255));
    itemBoxSizer15->Add(m_btClose, 0, wxGROW|wxALL, 5);

////@end WinEDA_bodytext_PropertiesFrame content construction
    m_btClose->SetFocus();
}

/*!
 * Should we show tooltips?
 */

bool WinEDA_bodytext_PropertiesFrame::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap WinEDA_bodytext_PropertiesFrame::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin WinEDA_bodytext_PropertiesFrame bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end WinEDA_bodytext_PropertiesFrame bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon WinEDA_bodytext_PropertiesFrame::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin WinEDA_bodytext_PropertiesFrame icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end WinEDA_bodytext_PropertiesFrame icon retrieval
}
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void WinEDA_bodytext_PropertiesFrame::OnOkClick( wxCommandEvent& event )
{
	bodytext_PropertiesAccept(event);
	Close();
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void WinEDA_bodytext_PropertiesFrame::OnCancelClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL in WinEDA_bodytext_PropertiesFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL in WinEDA_bodytext_PropertiesFrame.
}


/***************************************************************************/
void WinEDA_bodytext_PropertiesFrame::bodytext_PropertiesAccept(wxCommandEvent& event)
/***************************************************************************/
/* Met a jour les differents parametres pour le composant en cours d'edition
*/
{
LibDrawText* Text = (LibDrawText*) CurrentDrawItem;
wxString Line;

	Line = m_NewText->GetValue();
	g_LastTextOrient = m_Orient->GetValue() ? TEXT_ORIENT_VERT : TEXT_ORIENT_HORIZ;
	wxString msg = m_Size->GetValue();
	g_LastTextSize = ReturnValueFromString(g_UnitMetric, msg, m_Parent->m_InternalUnits);
	g_FlDrawSpecificConvert = m_CommonConvert->GetValue() ? FALSE : TRUE;
	g_FlDrawSpecificUnit = m_CommonUnit->GetValue() ? FALSE : TRUE;

	if ( Text )   // Set Pin Name & Num
	{
		if ( ! Line.IsEmpty() ) Text->m_Text = Line;
		else Text->m_Text = wxT("[null]");	// **** A REVOIR ***
		Text->m_Size.x = Text->m_Size.y = g_LastTextSize;
		Text->m_Horiz = g_LastTextOrient;
		if( g_FlDrawSpecificUnit ) Text->m_Unit = CurrentUnit;
		else Text->m_Unit = 0;
		if( g_FlDrawSpecificConvert ) Text->m_Convert = CurrentConvert;
		else Text->m_Convert = 0;
	}
	Close();

	if ( CurrentDrawItem )
		CurrentDrawItem->Display_Infos_DrawEntry(m_Parent);
}



/*******************************************************/
void WinEDA_LibeditFrame::EditSymbolText(wxDC * DC,
				LibEDA_BaseStruct * DrawItem)
/*******************************************************/
{
int DrawMode = g_XorMode;

	if ( DrawItem == NULL ) return;
	if ( DrawItem->Type() != COMPONENT_GRAPHIC_TEXT_DRAW_TYPE ) return;

	/* Effacement ancien texte */
	if( ((LibDrawText*)DrawItem)->m_Text && DC)
		DrawLibraryDrawStruct(DrawPanel, DC, CurrentLibEntry, wxPoint(0, 0),
			DrawItem, DrawMode);


	WinEDA_bodytext_PropertiesFrame * frame =
			new WinEDA_bodytext_PropertiesFrame(this);
	frame->ShowModal(); frame->Destroy();

	GetScreen()->SetModify();

	/* Affichage nouveau texte */
	if( ((LibDrawText*)DrawItem)->m_Text && DC)
	{
		if ( (DrawItem->m_Flags & IS_MOVED) == 0 )
			DrawMode = GR_DEFAULT_DRAWMODE;
		DrawLibraryDrawStruct(DrawPanel, DC, CurrentLibEntry, wxPoint(0, 0),
				DrawItem, DrawMode);
	}
}


/****************************************************/
void WinEDA_LibeditFrame::RotateSymbolText(wxDC * DC)
/****************************************************/
/*
	90 deg Graphic text Rotation .
*/
{
LibDrawText * DrawItem = (LibDrawText *) CurrentDrawItem;

	if(DrawItem == NULL) return;

	/* Erase drawing (can be within a move command) */
	if ( DrawPanel->ManageCurseur == NULL)
		DrawLibraryDrawStruct(DrawPanel, DC, CurrentLibEntry, wxPoint(0, 0),
				DrawItem, g_XorMode);
	else DrawPanel->ManageCurseur(DrawPanel, DC, FALSE);

	if( DrawItem->m_Horiz == TEXT_ORIENT_HORIZ)
			DrawItem->m_Horiz = TEXT_ORIENT_VERT;
	else DrawItem->m_Horiz = TEXT_ORIENT_HORIZ;

	GetScreen()->SetModify();

	/* Redraw item with new orient */
	if ( DrawPanel->ManageCurseur == NULL)
		DrawLibraryDrawStruct(DrawPanel, DC, CurrentLibEntry, wxPoint(0, 0),
				DrawItem, GR_DEFAULT_DRAWMODE);
	else DrawPanel->ManageCurseur(DrawPanel, DC, FALSE);

}


