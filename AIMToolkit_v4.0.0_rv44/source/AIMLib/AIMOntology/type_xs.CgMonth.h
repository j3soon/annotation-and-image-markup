#ifndef _ALTOVA_INCLUDED_AIMOntology_ALTOVA_xs_ALTOVA_CgMonth
#define _ALTOVA_INCLUDED_AIMOntology_ALTOVA_xs_ALTOVA_CgMonth



namespace AIMOntology
{

namespace xs
{	

class CgMonth : public TypeBase
{
public:
	AIMOntology_EXPORT CgMonth(xercesc::DOMNode* const& init);
	AIMOntology_EXPORT CgMonth(CgMonth const& init);
	void operator=(CgMonth const& other) { m_node = other.m_node; }
	static altova::meta::SimpleType StaticInfo() { return altova::meta::SimpleType(types + _altova_ti_xs_altova_CgMonth); }
	void operator= (const altova::DateTime& value) 
	{
		altova::XmlFormatter* Formatter = static_cast<altova::XmlFormatter*>(altova::GMonthFormatter);
		XercesTreeOperations::SetValue(GetNode(), Formatter->Format(value));
	}	
		
	operator altova::DateTime()
	{
		return CastAs<altova::DateTime >::Do(GetNode(), 0);
	}
};



} // namespace xs

}	// namespace AIMOntology

#endif // _ALTOVA_INCLUDED_AIMOntology_ALTOVA_xs_ALTOVA_CgMonth
