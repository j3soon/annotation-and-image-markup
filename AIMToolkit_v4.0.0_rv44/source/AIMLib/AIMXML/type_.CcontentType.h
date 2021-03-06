/*
*  2007 � 2013 Copyright Northwestern University
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CcontentType
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CcontentType



namespace AIMXML
{

class CcontentType : public TypeBase
{
public:
	AIMXML_EXPORT CcontentType(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CcontentType(CcontentType const& init);
	void operator=(CcontentType const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_altova_CcontentType); }
	AIMXML_EXPORT void operator=(const string_type& value);
	AIMXML_EXPORT operator string_type();

	MemberAttribute<string_type,_altova_mi_altova_CcontentType_altova_ID, 0, 0> ID;	// ID CID

	MemberAttribute<string_type,_altova_mi_altova_CcontentType_altova_language, 0, 0> language;	// language CNMTOKEN

	MemberAttribute<string_type,_altova_mi_altova_CcontentType_altova_styleCode, 0, 0> styleCode;	// styleCode CNMTOKENS
	MemberAttribute<string_type,_altova_mi_altova_CcontentType_altova_revised, 0, 2> revised;	// revised CrevisedType
	MemberElement<CcontentType, _altova_mi_altova_CcontentType_altova_content> content;
	struct content { typedef Iterator<CcontentType> iterator; };
	MemberElement<ClinkHtmlType, _altova_mi_altova_CcontentType_altova_linkHtml> linkHtml;
	struct linkHtml { typedef Iterator<ClinkHtmlType> iterator; };
	MemberElement<xs::CstringType, _altova_mi_altova_CcontentType_altova_sub> sub;
	struct sub { typedef Iterator<xs::CstringType> iterator; };
	MemberElement<xs::CstringType, _altova_mi_altova_CcontentType_altova_sup> sup;
	struct sup { typedef Iterator<xs::CstringType> iterator; };
	MemberElement<CbrType, _altova_mi_altova_CcontentType_altova_br> br;
	struct br { typedef Iterator<CbrType> iterator; };
	MemberElement<CfootnoteType, _altova_mi_altova_CcontentType_altova_footnote> footnote;
	struct footnote { typedef Iterator<CfootnoteType> iterator; };
	MemberElement<CfootnoteRefType, _altova_mi_altova_CcontentType_altova_footnoteRef> footnoteRef;
	struct footnoteRef { typedef Iterator<CfootnoteRefType> iterator; };
	MemberElement<CrenderMultiMediaType, _altova_mi_altova_CcontentType_altova_renderMultiMedia> renderMultiMedia;
	struct renderMultiMedia { typedef Iterator<CrenderMultiMediaType> iterator; };
	AIMXML_EXPORT void SetXsiType();
};


}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA__ALTOVA_CcontentType
