#pragma once
//#include "../stdafx.h"

#include <map>

#if defined(_WIN32) || defined (_WIN64)
	#include <atlbase.h>
	#include <atlstr.h>
#else
	#include "../../Common/DocxFormat/Source/Base/ASCString.h"
#endif

#include "../../DesktopEditor/fontengine/ApplicationFonts.h"
//#include "DocWrapper/Base.h"
namespace NSCommon{
	template<class Type> class nullable;
}
namespace ComplexTypes{
    namespace Spreadsheet{
        class CString_;
    }
}
namespace OOX
{
	class CFont;
	class CFontTable;
	class CTheme;
	namespace Spreadsheet
	{
		class CFont;
		class CFontTable;
		class CFontScheme;
		class CString_;
		class CCharset;
		class CFontFamily;
	}
}

namespace DocWrapper {
	
	class FontProcessor {
		CFontManager* m_pFontManager;
		std::map<CString, CString> fontMap;

	public:
		FontProcessor();
		~FontProcessor();
		
		void setFontManager(CFontManager* pFontManager);
		CFontManager* getFontManager();
		void setFontTable(OOX::CFontTable* fontTable);
		
		CString getFont(const CString& name);
		CString getFont(const NSCommon::nullable<OOX::Spreadsheet::CFontScheme>& oScheme, const NSCommon::nullable<ComplexTypes::Spreadsheet::CString_>& oRFont, const NSCommon::nullable<OOX::Spreadsheet::CCharset>& oCharset, const NSCommon::nullable<OOX::Spreadsheet::CFontFamily >& oFamily, OOX::CTheme* pTheme);		
	private:
		void addToFontMap(OOX::CFont& font);
	};
	
}
