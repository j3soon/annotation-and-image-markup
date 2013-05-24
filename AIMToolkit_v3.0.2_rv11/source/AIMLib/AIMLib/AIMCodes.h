/*
*  Copyright Northwestern University
*  Copyright Stanford University (ATB 1.0 and ATS 1.0)
*
*  Distributed under the OSI-approved BSD 3-Clause License.
*  See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
*/

#if !defined(_AIMLib_AIMCodes_Class)
#define _AIMLib_AIMCodes_Class

#include <string>
#include <map>
#include <vector>

#include "dcmtk/dcmsr/dsrdoc.h"

namespace aim_lib
{
	// private coding scheme designator used for internal codes
	#define AIM_CODING_SCHEME_DESIGNATOR "99NCIAIM"
	// coding scheme version
	#define AIM_CODING_SCHEME_VERSION "04"
	// name of the private coding scheme
	#define AIM_CODING_SCHEME_NAME "AIM Coding Scheme"
	// organization responsible for the private coding scheme
	#define AIM_RESPONSIBLE_ORGANIZATION "Northwestern University, Department of Raiology, Imaging and Informatics Section, Chicago, IL, USA"


	class AIMCodes
	{
	public:
		~AIMCodes(void);

		static const DSRCodedEntryValue GetCalculationResultTypeValue(CalculationResult::CalculationResultType calculationResultType);
		static const DSRCodedEntryValue GetOrganizationalRoleValue(const std::string& organizationalRoleName);
		static const DSRCodedEntryValue GetPerformingRoleValue(const std::string& performmingRoleName);
		static const DSRCodedEntryValue GetUcumCodeValue(const std::string& unitAbbreviation);
		static const DSRCodedEntryValue GetCharacteristicQuantificationTypeValue(CharacteristicQuantification::QuantificationType charQuantificationType);
		static const DSRCodedEntryValue GetComparisonOperatorTypeValue(ComparisonOperatorType comparisonOperatorType);
		static const ComparisonOperatorType GetComparisonOperatorType(const DSRCodedEntryValue& comparisonOperatorCode);
		static const DSRCodedEntryValue GetBooleanCodeValue(bool boolValue);
		static const DSRCodedEntryValue GetScaleTypeValue(Scale::ScaleType scaleType);
		static const Scale::ScaleType GetScaleType(const DSRCodedEntryValue& scaleTypeCode);
		static const DSRCodedEntryValue GetEntityValue(const std::string& entityClassName);
		static const std::string& GetEntityClassName(const DSRCodedEntryValue& entityCode);
		static const DSRCodedEntryValue GetStatementPredicateValue(const std::string& statementPredicateClassName);
		static const std::string& GetStatementPredicateClassName(const DSRCodedEntryValue& statementPredicateCode);

		static const DSRCodedEntryValue EmptyCodedEntryValue; // returned when no matching value is found in the map
		static const DSRSpatialCoordinatesValue EmptySpatialCoordinateValue; // empty 2D spatial coordinate
		static const DSRSpatialCoordinates3DValue EmptySpatialCoordinate3DValue; // empty 3D spatial coordinate
		static const DSRImageReferenceValue EmptyImageReferenceValue; // empty image reference
		static const DSRNumericMeasurementValue EmptyNumericMeasurementValue; // empty numeric value

		// Creates DSRCodedEntryValue with the given arguments
		static const DSRCodedEntryValue CreateCodedEntryValue(const std::string& codeValue, const std::string& codeMeaning, const std::string& codingSchemeDesignator, const std::string& codingSchemeVersion = _T(""));

		// Creates AIM's DSRCodedEntryValue:
		// (codingSchemeDesignator = AIM_CODING_SCHEME_DESIGNATOR; codingScemeVersion = AIM_CODING_SCHEME_VERSION)
		static const DSRCodedEntryValue CreateAimCodedEntryValue(const std::string& codeValue, const std::string& codeMeaning);

		static DSRCodedEntryValue CreateCodedEntryValueFromCd(const iso_21090::CD& cd);
		static iso_21090::CD CreateCdFromCodedEntryValue(const DSRCodedEntryValue& dsrCode);

	protected:
		AIMCodes(void);

		// These are typedef'ed maps used during various code lookups
		typedef std::map<std::string, std::string> StringMap; // used when all codes belong to the same Coding Scheme
		typedef std::map<std::string, std::pair<std::string, std::string> > String2PairMap; // used when codes come from different Coding Schemes
		typedef std::map<std::string, DSRCodedEntryValue> String2CodedEntryValueMap;
		typedef std::map<CalculationResult::CalculationResultType, DSRCodedEntryValue> CalcResultTypeMap;
		typedef std::map<CharacteristicQuantification::QuantificationType, DSRCodedEntryValue> CharQuantificationTypeMap;
		typedef std::map<ComparisonOperatorType, DSRCodedEntryValue> ComparisonOperatorTypeMap;
		typedef std::map<bool, DSRCodedEntryValue> BooleanTypeMap;
		typedef std::map<Scale::ScaleType, DSRCodedEntryValue> ScaleTypeMap;

		template<typename T, typename M>
		static const M FindMapValue(const std::map<T,M>& theMap, const T& lookupValue, const M& defaultValue);

		template<typename T>
		static const T& FindMapKeyByCodeValue(const std::map<T,DSRCodedEntryValue>& theMap, const DSRCodedEntryValue& lookupValue, const T& defaultValue);

		// Do actual lookup
		static const DSRCodedEntryValue GetMappedValue(const StringMap& lookupMap, const std::string& codingScheme, const std::string& lookupValue);
		static const DSRCodedEntryValue GetMappedValue(const String2PairMap& lookupMap, const std::string& lookupValue);

		// Calculation Result Types
		static const CalcResultTypeMap InitializeCalculationResultTypes();

		// Organizational Roles - BCID(7452)
		static const StringMap InitializeOrganizationalRoles();

		// Performing Roles - BCID(7453)
		static const StringMap InitializePerformingRoles();

		// UCUM Units
		static const StringMap InitializeUcumUnits();

		// Characteristic Quantification Types - aimcid013
		static const CharQuantificationTypeMap InitializeCharQuantificationTypes();

		// Comparison Operator Types
		static const ComparisonOperatorTypeMap InitializeComparisonOperatorTypes();
		static const ComparisonOperatorTypeMap& GetComparisonOperatorTypes();

		// Boolean
		static const BooleanTypeMap InitializeBooleanTypes();

		// Scale Types - aimcid015
		static const ScaleTypeMap InitializeScaleTypes();
		static const ScaleTypeMap& GetScaleTypes();

		// Annotation Entities - aimcid016
		static const String2CodedEntryValueMap InitializeAnnotationEnities();
		static const String2CodedEntryValueMap& GetAnnotationEnities();

		// AIM Statements Predicates - aimcid017
		static const String2CodedEntryValueMap InitializeStatementPredicates();
		static const String2CodedEntryValueMap& GetStatementPredicates();

		static const std::string _emptyStr;
	};
}

#endif // _AIMLib_AIMCodes_Class
