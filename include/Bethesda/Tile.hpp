#pragma once
#include "Types.hpp"
#include "Bethesda/BSSimpleArray.hpp"
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/BSStringT.hpp"
#include "Gamebryo/NiNode.hpp"
#include "Gamebryo/NiExtraData.hpp"
#include "Gamebryo/NiRect.hpp"
#include "Gamebryo/NiTStringPointerMap.hpp"

// TO DO
namespace CommonLib {

  class Tile
  {
    public:
      Tile();
      virtual ~Tile();

      class BuildStorage;
      class TileTemplate;

      enum enumMisc
      {
        eFalse = 0x0,
        eTrue = 0x1,
        eXenon = 0x1,
        eLeftJustify = 0x1,
        eCenterJustify = 0x2,
        eRightJustify = 0x4,
        eUp = 0x5,
        eDown = 0x6,
        eUseLocalColor = 0xFFFFFFFF,
        eScale = 0xFFFFFFFF,
        eGeneric = 0xFFFFFFFF,
        eNoSound = 0xFFFFFFFF,
        eNoSystemColor = 0x0,
        eDefaultSystemColor = 0x1,
        eSystemColorMain = 0x1,
        eSystemColorWarning = 0x2,
        eSystemColorTerminal = 0x3,
        eSystemColorPipboy = 0x4,
        eClickPast = 0x65,
        eNoClickPast = 0x66,
        eMixedMenu = 0x67,
        eGlowBranch = 0x6E,
        eNoGlowBranch = 0x6F,
        ePipBoy = 0x70,
      };

      enum enumType
      {
        eNullType = 0x0,
        eFirstType = 0x385,
        eRect = 0x385,
        eImage = 0x386,
        e3D = 0x388,
        eMenu = 0x389,
        eHotRect = 0x38A,
        eWindow = 0x38B,
        eRadial = 0x38C,
        eLastType = 0x38C,
        eTemplate = 0x3E7,
      };

      enum TEMPLATE_ID 
      {
        TI_GROUP_START = 0x0,
        TI_GROUP_END = 0x1,
        TI_ACTION_START = 0x2,
        TI_ACTION_END = 0x3,
        TI_TRAIT_START = 0x4,
        TI_TRAIT_END = 0x5,
        TI_TILE_START = 0x6,
        TI_TILE_END = 0x7,
        TI_SIMPLE_TRAIT = 0x8,
        TI_SIMPLE_ACTION = 0x9,
        TI_TRAIT_LINK = 0xA,
      };

      enum VALUE_ACTION 
      {
        VA_COPY = 0x7D0,
        VA_ADD = 0x7D1,
        VA_SUB = 0x7D2,
        VA_MULT = 0x7D3,
        VA_DIV = 0x7D4,
        VA_MIN = 0x7D5,
        VA_MAX = 0x7D6,
        VA_MOD = 0x7D7,
        VA_FLOOR = 0x7D8,
        VA_CEIL = 0x7D9,
        VA_ABS = 0x7DA,
        VA_ROUND = 0x7DB,
        VA_GT = 0x7DC,
        VA_GTE = 0x7DD,
        VA_EQ = 0x7DE,
        VA_NEQ = 0x7DF,
        VA_LT = 0x7E0,
        VA_LTE = 0x7E1,
        VA_AND = 0x7E2,
        VA_OR = 0x7E3,
        VA_NOT = 0x7E4,
        VA_ONLYIF = 0x7E5,
        VA_ONLYIFNOT = 0x7E6,
        VA_REF = 0x7E7,
        VA_LEFT_PAREN = 0x7E8,
        VA_RIGHT_PAREN = 0x7E9,
        VA_FIRST_ACTION = 0x7D0,
        VA_LAST_ACTION = 0x7E9,
      };

      enum enumTag
      {
        eNullTag = 0x0,
        eFirstTag = 0xBB9,
        eValue = 0xBB9,
        eName = 0xBBA,
        eSrc = 0xBBB,
        eTrait = 0xBBC,
        eLastTag = 0xBBC,
      };

      enum enumTrait
      {
        eNullTrait = 0x0,
        eX = 0xFA1,
        eFirstTrait = 0xFA1,
        eY = 0xFA2,
        eVisible = 0xFA3,
        eClass = 0xFA4,
        eClipWindow = 0xFA6,
        eStackingType = 0xFA7,
        eLocus = 0xFA8,
        eAlpha = 0xFA9,
        eID = 0xFAA,
        eDisableFade = 0xFAB,
        eListIndex = 0xFAC,
        eDepth = 0xFAD,
        eClips = 0xFAE,
        eTarget = 0xFAF,
        eHeight = 0xFB0,
        eWidth = 0xFB1,
        eRed = 0xFB2,
        eGreen = 0xFB3,
        eBlue = 0xFB4,
        eTile = 0xFB5,
        eChildCount = 0xFB6,
        eJustify = 0xFB7,
        eZoom = 0xFB8,
        eFont = 0xFB9,
        eWrapWidth = 0xFBA,
        eWrapLimit = 0xFBB,
        eWrapLines = 0xFBC,
        ePageNum = 0xFBD,
        eIsHTML = 0xFBE,
        eCropy = 0xFBF,
        eCropx = 0xFC0,
        eMenuFade = 0xFC1,
        eExploreFade = 0xFC2,
        eMouseOver = 0xFC3,
        eString = 0xFC4,
        eShiftClicked = 0xFC5,
        eClicked = 0xFC7,
        eClickSound = 0xFCB,
        eFilename = 0xFCC,
        eFilewidth = 0xFCD,
        eFileheight = 0xFCE,
        eRepeatVertical = 0xFCF,
        eRepeatHorizontal = 0xFD0,
        eAnimation = 0xFD2,
        eLineCount = 0xFD4,
        ePageCount = 0xFD5,
        eXDefault = 0xFD6,
        eXUp = 0xFD7,
        eXDown = 0xFD8,
        eXLeft = 0xFD9,
        eXRight = 0xFDA,
        eXButtonA = 0xFDD,
        eXButtonB = 0xFDE,
        eXButtonX = 0xFDF,
        eXButtonY = 0xFE0,
        eXButtonLT = 0xFE1,
        eXButtonRT = 0xFE2,
        eXButtonLB = 0xFE3,
        eXButtonRB = 0xFE4,
        eXButtonLS = 0xFE5,
        eXButtonRS = 0xFE6,
        eXButtonStart = 0xFE7,
        eMouseOverSound = 0xFE8,
        eDraggable = 0xFE9,
        eDragStartX = 0xFEA,
        eDragStartY = 0xFEB,
        eDragOffsetX = 0xFEC,
        eDragOffsetY = 0xFED,
        eDragDeltaX = 0xFEE,
        eDragDeltaY = 0xFEF,
        eDragX = 0xFF0,
        eDragY = 0xFF1,
        eWheelable = 0xFF2,
        eWheelMoved = 0xFF3,
        eSystemColor = 0xFF4,
        eBrightness = 0xFF5,
        eLineGap = 0xFF7,
        eResolutionConverter = 0xFF8,
        eTexAtlas = 0xFF9,
        eRotateAngle = 0xFFA,
        eRotateAxisX = 0xFFB,
        eRotateAxisY = 0xFFC,
        eUser0 = 0x1004,
        eUser1 = 0x1005,
        eUser2 = 0x1006,
        eUser3 = 0x1007,
        eUser4 = 0x1008,
        eUser5 = 0x1009,
        eUser6 = 0x100A,
        eUser7 = 0x100B,
        eUser8 = 0x100C,
        eUser9 = 0x100D,
        eUser10 = 0x100E,
        eUser11 = 0x100F,
        eUser12 = 0x1010,
        eUser13 = 0x1011,
        eUser14 = 0x1012,
        eUser15 = 0x1013,
        eUser16 = 0x1014,
        eLastTrait = 0x101D,
        eMenuLevel = 0x1771,
        eDeleteOnFade = 0x1772,
        eMenuThickness = 0x1773,
        eNoClickPastDone = 0x1776,
        eMixedMenuDone = 0x1777,
        eDoesNotStack = 0x1778,
        eMenuVisible = 0x1779,
      };

      enum enumKeyword
      {
        eNullKeyword = 0x0,
        eParent = 0x1389,
        eMe = 0x138A,
        eSibling = 0x138C,
        eChild = 0x138D,
        eScreen = 0x138E,
        eGlobals = 0x138F,
        eIO = 0x1390,
        eGrandParent = 0x1391,
      };

      enum enumbfUpdate 
      {
        ebfPosition = 0x1,
        ebfCreate = 0x2,
        ebfVisibility = 0x4,
        ebfColor = 0x8,
        ebfGeometry = 0x10,
        ebfTexture = 0x20,
        ebfNIFFile = 0x40,
        ebfScissorWindow = 0x80,
        ebfScissor = 0x100,
        ebfLocus = 0x200,
        ebfNeedsUpdateMask = 0x3FF,
        ebfDirty = 0x400,
        ebfHibernated = 0x800,
        ebfPromoted = 0x1000,
        ebfReleased = 0x2000,
        ebfMenuDeleting = 0x4000,
        ebfManualUpdateTris = 0x8000,
        ebfTileLoading = 0x10000,
        ebfModelFromModelLoader = 0x20000,
      };

      enum enumWORDTYPE
      {
        eEmpty = 0x0,
        eStart = 0x1,
        eClosed = 0x2,
        eEnd = 0x3,
        eData = 0x4,
      };

      enum enumXMLname 
      {
        TAG_START = 0x0,
        TAG_NAME = 0x1,
        TAG_CLOSE = 0x2,
        TAG_DATA = 0x3,
        TAG_COMMENT = 0x4,
        ATTR_NAME = 0x5,
        ATTR_VALUE = 0x6,
      };

      enum TILE_FADE_CONTROL_TYPE
      {
        TFCT_STANDARD = 0x0,
        TFCT_NONLINEAR_LONG_DARK_REPEATING = 0x1,
        TFCT_BLINK_THRICE = 0x2,
        TFCT_BLINK_FAST_FADE = 0x3,
        TFCT_FADE_IN_HOLD_FADE_OUT = 0x4,
      };

      class Action
      {
        public:
          Action();
          virtual ~Action();

          VALUE_ACTION eActionType;
          Action *pnext;
      };

      class Value
      {
        public:

          enumTrait eIndex;
          Tile *pParent;
          float fValue;
          char *strValue;
          Action *pActionListA;
      };

      struct FadeControl
      {
        float fStartValue;
        float fEndValue;
        unsigned int uiStartTime;
        float fDurationMillis;
        enumTrait iTrait;
        Tile *pParent;
        TILE_FADE_CONTROL_TYPE eFadeType;
      };

      union TileTemplateUnion
      {
        int iTA;
        Tile *pTile;
        TileTemplate *pTemplate;
      };

      class TileTemplateItem
      {
        public:

          int iCmd;
          float fVal;
          BSStringT<char> xStr;
          TileTemplateUnion u;
          int iLine;
      };
      
      class TileTemplate
      {
        public:

          NiFixedString xName;
          BuildStorage *pParent;
          NiTPointerList<TileTemplateItem *> xList;
      };

      class BuildStorage
      {
        public:

          TileTemplate *pTemplate;
          BSSimpleList<TileTemplate *> xSubTemplates;
          TileTemplate *pCurrentTemplate;
          bool bDeleteTemplates;
      };

      class FloatAction : public Action
      {
        public:
          FloatAction();
          virtual ~FloatAction();

          float fValue;
      };

      class RefValueAction : public Action
      {
        public:
          RefValueAction();
          virtual ~RefValueAction();

          Value *pRefValue;
      };

      class Reaction
      {
        public:

          Value *preactionValue;
          Reaction *pnext;
      };

      class Extra : public NiExtraData
      {
        public:
          Extra();
          virtual ~Extra();

          Tile *pTile;
          NiNode *pNode;
      };

      class TextureAtlasEntry
      {
        public:

          BSStringT<char> strAtlasFilename;
          BSStringT<char> strSubtexture;
          BSStringT<char> strAtlasTexture;
          NiRect<float> SubRect;
      };

      class MenuStringMap : NiTStringPointerMap<int>
      {
        public:
          MenuStringMap();
          virtual ~MenuStringMap();
      };


      NiTPointerList<Tile *> xChildren;
      BSSimpleArray<Tile::Value *,8> xTraits;
      BSStringT<char> xName;
      Tile *pParent;
      NiPointer<NiNode> spModel;
      unsigned int uiFlags;
      bool bNeedsNiUpdate;
      bool bSpeechChallengeFailure;
  };

  static_assert(sizeof(Tile) == 0x38, "Tile has wrong size");
  
} // namespace CommonLib
