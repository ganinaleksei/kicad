#ifndef __EESCHEMA_ID_H__
#define __EESCHEMA_ID_H__


#include "id.h"

/**
 * Command IDs for the schematic editor.
 *
 * Please add IDs that are unique to the schematic editor (EESchema) here and
 * not in the global id.h file.  This will prevent the entire project from
 * being rebuilt when adding new command to EESchema.
 */

enum id_eeschema_frm
{
    /* Schematic editor horizontal toolbar IDs */
    ID_HIERARCHY = ID_END_LIST,
    ID_TO_LIBVIEW,
    ID_GET_ANNOTATE,
    ID_GET_ERC,
    ID_BACKANNO_ITEMS,

    /* Schematic editor veritcal toolbar IDs */
    ID_SCHEMATIC_VERTICAL_TOOLBAR_START,
    ID_HIERARCHY_PUSH_POP_BUTT,
    ID_PLACE_POWER_BUTT,
    ID_BUS_BUTT,
    ID_WIRE_BUTT,
    ID_BUSTOBUS_ENTRY_BUTT,
    ID_WIRETOBUS_ENTRY_BUTT,
    ID_LABEL_BUTT,
    ID_GLABEL_BUTT,
    ID_HIERLABEL_BUTT,
    ID_IMPORT_HLABEL_BUTT,
    ID_SHEET_LABEL_BUTT,
    ID_NOCONN_BUTT,
    ID_JUNCTION_BUTT,
    ID_SHEET_SYMBOL_BUTT,
    ID_TEXT_COMMENT_BUTT,
    ID_LINE_COMMENT_BUTT,
    ID_SCHEMATIC_DELETE_ITEM_BUTT,
    ID_SCHEMATIC_VERTICAL_TOOLBAR_END,

    /* Schematic editor context menu IDs. */
    ID_POPUP_SCH_COPY_ITEM,

    ID_POPUP_START_RANGE,
    ID_POPUP_SCH_DELETE,
    ID_POPUP_SCH_BREAK_WIRE,
    ID_POPUP_SCH_DELETE_CONNECTION,
    ID_POPUP_SCH_MOVE_ITEM_REQUEST,
    ID_POPUP_SCH_DELETE_NODE,
    ID_POPUP_SCH_MOVE_CMP_REQUEST,
    ID_POPUP_SCH_DELETE_CMP,
    ID_POPUP_SCH_DRAG_CMP_REQUEST,
    ID_POPUP_SCH_DRAG_WIRE_REQUEST,
    ID_POPUP_SCH_UNUSED_2,
    ID_POPUP_SCH_ENTRY_SELECT_SLASH,
    ID_POPUP_SCH_ENTRY_SELECT_ANTISLASH,

    ID_POPUP_SCH_EDIT_CMP,
    ID_POPUP_SCH_MIROR_X_CMP,
    ID_POPUP_SCH_MIROR_Y_CMP,
    ID_POPUP_SCH_ROTATE_CMP_CLOCKWISE,
    ID_POPUP_SCH_ROTATE_CMP_COUNTERCLOCKWISE,
    ID_POPUP_SCH_ORIENT_NORMAL_CMP,
    ID_POPUP_SCH_INIT_CMP,

    ID_POPUP_SCH_EDIT_TEXT,
    ID_POPUP_SCH_ROTATE_TEXT,
    ID_POPUP_SCH_SET_SHAPE_TEXT,
    ID_POPUP_END_LINE,
    ID_POPUP_SCH_END_SHEET,
    ID_POPUP_SCH_EDIT_SHEET,
    ID_POPUP_SCH_RESIZE_SHEET,
    ID_POPUP_SCH_CLEANUP_SHEET,
    ID_POPUP_SCH_EDIT_PINSHEET,
    ID_POPUP_SCH_MOVE_PINSHEET,
    ID_POPUP_IMPORT_GLABEL,
    ID_POPUP_SCH_GENERIC_ORIENT_CMP,
    ID_POPUP_SCH_GENERIC_EDIT_CMP,
    ID_POPUP_SCH_EDIT_VALUE_CMP,
    ID_POPUP_SCH_EDIT_REF_CMP,
    ID_POPUP_SCH_EDIT_FOOTPRINT_CMP,
    ID_POPUP_SCH_EDIT_CONVERT_CMP,
    ID_POPUP_SCH_SELECT_UNIT_CMP,
    ID_POPUP_SCH_SELECT_UNIT1,
    ID_POPUP_SCH_SELECT_UNIT2,
    ID_POPUP_SCH_SELECT_UNIT3,
    ID_POPUP_SCH_SELECT_UNIT4,
    ID_POPUP_SCH_SELECT_UNIT5,
    ID_POPUP_SCH_SELECT_UNIT6,
    ID_POPUP_SCH_SELECT_UNIT7,
    ID_POPUP_SCH_SELECT_UNIT8,
    ID_POPUP_SCH_SELECT_UNIT9,
    ID_POPUP_SCH_SELECT_UNIT10,
    ID_POPUP_SCH_SELECT_UNIT11,
    ID_POPUP_SCH_SELECT_UNIT12,
    ID_POPUP_SCH_SELECT_UNIT13,
    ID_POPUP_SCH_SELECT_UNIT14,
    ID_POPUP_SCH_SELECT_UNIT15,
    ID_POPUP_SCH_SELECT_UNIT16,
    ID_POPUP_SCH_SELECT_UNIT17,
    ID_POPUP_SCH_SELECT_UNIT18,
    ID_POPUP_SCH_SELECT_UNIT19,
    ID_POPUP_SCH_SELECT_UNIT20,
    ID_POPUP_SCH_SELECT_UNIT21,
    ID_POPUP_SCH_SELECT_UNIT22,
    ID_POPUP_SCH_SELECT_UNIT23,
    ID_POPUP_SCH_SELECT_UNIT24,
    ID_POPUP_SCH_SELECT_UNIT25,
    ID_POPUP_SCH_SELECT_UNIT26,
    ID_POPUP_SCH_ROTATE_FIELD,
    ID_POPUP_SCH_EDIT_FIELD,
    ID_POPUP_SCH_CHANGE_TYPE_TEXT,
    ID_POPUP_SCH_CHANGE_TYPE_TEXT_TO_LABEL,
    ID_POPUP_SCH_CHANGE_TYPE_TEXT_TO_GLABEL,
    ID_POPUP_SCH_CHANGE_TYPE_TEXT_TO_COMMENT,
    ID_POPUP_SCH_DISPLAYDOC_CMP,
    ID_POPUP_SCH_ENTER_SHEET,
    ID_POPUP_SCH_LEAVE_SHEET,
    ID_POPUP_SCH_ADD_JUNCTION,
    ID_POPUP_SCH_ADD_LABEL,
    ID_POPUP_SCH_ADD_GLABEL,
    ID_POPUP_SCH_CHANGE_TYPE_TEXT_TO_HLABEL,
    ID_POPUP_SCH_GETINFO_MARKER,
    ID_POPUP_END_RANGE,

    /* Library editor horizontal toolbar IDs. */
	ID_LIBEDIT_SELECT_PART,
	ID_LIBEDIT_SELECT_CURRENT_LIB,
	ID_LIBEDIT_SAVE_CURRENT_LIB,
	ID_LIBEDIT_SAVE_CURRENT_PART,
	ID_LIBEDIT_NEW_PART,
	ID_LIBEDIT_GET_FRAME_EDIT_PART,
	ID_LIBEDIT_GET_FRAME_EDIT_FIELDS,
	ID_LIBEDIT_DELETE_PART,
	ID_DE_MORGAN_NORMAL_BUTT,
	ID_DE_MORGAN_CONVERT_BUTT,
	ID_LIBEDIT_EDIT_PIN_BY_PIN,
	ID_LIBEDIT_VIEW_DOC,
    ID_LIBEDIT_CHECK_PART,

	ID_LIBEDIT_SELECT_PART_NUMBER,
	ID_LIBEDIT_SELECT_ALIAS,

	/* Library editor vertical toolbar IDs. */
	ID_LIBEDIT_PIN_BUTT,
	ID_LIBEDIT_BODY_LINE_BUTT,
	ID_LIBEDIT_BODY_ARC_BUTT,
	ID_LIBEDIT_BODY_CIRCLE_BUTT,
	ID_LIBEDIT_BODY_RECT_BUTT,
	ID_LIBEDIT_BODY_TEXT_BUTT,
	ID_LIBEDIT_DELETE_ITEM_BUTT,
	ID_LIBEDIT_ANCHOR_ITEM_BUTT,
	ID_LIBEDIT_IMPORT_BODY_BUTT,
	ID_LIBEDIT_EXPORT_BODY_BUTT,

    /* Library editor context menu IDs */
	ID_LIBEDIT_EDIT_PIN,
	ID_LIBEDIT_ROTATE_PIN,
	ID_POPUP_LIBEDIT_PIN_GLOBAL_CHANGE_ITEM,
	ID_POPUP_LIBEDIT_PIN_GLOBAL_CHANGE_PINSIZE_ITEM,
	ID_POPUP_LIBEDIT_PIN_GLOBAL_CHANGE_PINNAMESIZE_ITEM,
	ID_POPUP_LIBEDIT_PIN_GLOBAL_CHANGE_PINNUMSIZE_ITEM,
	ID_POPUP_LIBEDIT_BODY_EDIT_ITEM,
	ID_POPUP_LIBEDIT_DELETE_ITEM,
	ID_POPUP_LIBEDIT_MODIFY_ITEM,
	ID_POPUP_LIBEDIT_END_CREATE_ITEM,
	ID_POPUP_LIBEDIT_CANCEL_EDITING,
	ID_POPUP_LIBEDIT_MOVE_ITEM_REQUEST,
	ID_POPUP_LIBEDIT_FIELD_EDIT_ITEM,
	ID_POPUP_LIBEDIT_FIELD_ROTATE_ITEM,
	ID_POPUP_LIBEDIT_DELETE_CURRENT_POLY_SEGMENT,
	ID_POPUP_LIBEDIT_ROTATE_GRAPHIC_TEXT,
    
    /* Library editor menubar IDs */
    ID_LIBEDIT_SAVE_CURRENT_LIB_AS,
    ID_LIBEDIT_GEN_PNG_FILE,
    ID_LIBEDIT_GEN_SVG_FILE,

    /* Library viewer horizontal toolbar IDs */
    ID_LIBVIEW_NEXT,
    ID_LIBVIEW_PREVIOUS,
    ID_LIBVIEW_SELECT_PART,
    ID_LIBVIEW_SELECT_LIB,
    ID_LIBVIEW_VIEWDOC,
    ID_LIBVIEW_DE_MORGAN_NORMAL_BUTT,
    ID_LIBVIEW_DE_MORGAN_CONVERT_BUTT,
    ID_LIBVIEW_SELECT_PART_NUMBER,
    ID_LIBVIEW_LIB_LIST,
    ID_LIBVIEW_CMP_LIST,
    ID_LIBVIEW_LIBWINDOW,
    ID_LIBVIEW_CMPWINDOW,
    ID_LIBVIEW_CMP_EXPORT_TO_SCHEMATIC,
    ID_SET_RELATIVE_OFFSET
};


#endif  /* __EESCHEMA_ID_H__ */
