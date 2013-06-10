#region License

//L
// 2007 - 2013 Copyright Northwestern University
//
// Distributed under the OSI-approved BSD 3-Clause License.
// See http://ncip.github.com/annotation-and-image-markup/LICENSE.txt for details.
//L

#endregion

using System;
using System.Collections;
using System.Data;
using DataServiceUtil;

namespace NBIAService
{
	public class NBIASeries : NBIAQueryBase
	{

		public DataTable getSeriesInfo(NBIAQueryParameters queryParameters, string endPointUrl)
		{
			_queryParameters = queryParameters;
			DataTable dataTable = null;
			var result = getSeriesCQLInfo(endPointUrl);
			if (result != null && result.Items != null && result.Items.Length > 0)
				dataTable = processCQLObjectResult(result);
			return dataTable;
		}

		private CQLQueryResults getSeriesCQLInfo(string endPointUrl)
		{
			object[] obj;
			CQLQueryResults result;
			Association assoImage = null;
			Association assoTrialDataProvenance = null;
			Association assoClinicalTrialSite = null;
			Association assoClinicalTrialProtocol = null;
			Association assoClinicalTrialSubject = null;
			Association assoPatient = null;
			Association assoStudy = null;
			var results = new ArrayList();
			var proxy = new NCIACoreServicePortTypeClient();
			proxy.Endpoint.Address = new System.ServiceModel.EndpointAddress(endPointUrl);
			var items = new[] { "modality", "instanceUID" };
			var itemsChoiceType1 = new[] {
                ItemsChoiceType.AttributeNames, ItemsChoiceType.AttributeNames};

			if (!_queryParameters.ProjectName.IsEmpty)
			{
				var attrTrialDataProvenance = CreateAttribute("project", _queryParameters.ProjectName);
				var grpTrialDataProvenance = CreateQRAttrAssoGroup.createGroup(attrTrialDataProvenance, LogicalOperator.AND);
				assoTrialDataProvenance = CreateQRAttrAssoGroup.createAssociation("gov.nih.nci.ncia.domain.TrialDataProvenance", "dataProvenance", grpTrialDataProvenance);
			}
			assoClinicalTrialSite = null;
			obj = null;
			results = new ArrayList();
			if (!_queryParameters.SiteId.IsEmpty)
				results.Add(CreateAttribute("siteId", _queryParameters.SiteId));
			if (!_queryParameters.SiteName.IsEmpty)
				results.Add(CreateAttribute("siteName", _queryParameters.SiteName));
			if (results.Count > 0)
				obj = (object[])results.ToArray(typeof(object));
			if (obj != null)
			{
				var grpClinicalTrialSite = CreateQRAttrAssoGroup.createGroup(obj, LogicalOperator.AND);
				assoClinicalTrialSite = CreateQRAttrAssoGroup.createAssociation("gov.nih.nci.ncia.domain.ClinicalTrialSite", "site", grpClinicalTrialSite);
			}
			assoClinicalTrialProtocol = null;
			obj = null;
			results = new ArrayList();
			if (!_queryParameters.ProtocolId.IsEmpty)
				results.Add(CreateAttribute("protocolId", _queryParameters.ProtocolId));
			if (!_queryParameters.ProtocolName.IsEmpty)
				results.Add(CreateAttribute("protocolName", _queryParameters.ProtocolName));
			if (results.Count > 0)
				obj = (object[])results.ToArray(typeof(object));
			if (obj != null)
			{
				var grpClinicalTrialProtocol = CreateQRAttrAssoGroup.createGroup(obj, LogicalOperator.AND);
				assoClinicalTrialProtocol = CreateQRAttrAssoGroup.createAssociation("gov.nih.nci.ncia.domain.ClinicalTrialProtocol",
																							"protocol", grpClinicalTrialProtocol);
			}
			obj = null;
			results = new ArrayList();
			assoClinicalTrialSubject = null;
			if (assoClinicalTrialSite != null)
				results.Add(assoClinicalTrialSite);
			if (assoClinicalTrialProtocol != null)
				results.Add(assoClinicalTrialProtocol);
			if (results.Count > 0)
				obj = (object[])results.ToArray(typeof(object));
			if (obj != null)
			{
				var grpClinicalTrialSubject = CreateQRAttrAssoGroup.createGroup(obj, LogicalOperator.AND);
				assoClinicalTrialSubject = CreateQRAttrAssoGroup.createAssociation("gov.nih.nci.ncia.domain.ClinicalTrialSubject",
																							   "subjectCollection", grpClinicalTrialSubject);
			}
			obj = null;
			results = new ArrayList();
			if (assoClinicalTrialSubject != null)
				results.Add(assoClinicalTrialSubject);
			if (assoTrialDataProvenance != null)
				results.Add(assoTrialDataProvenance);
			if (!_queryParameters.PatientBirthDate.IsEmpty)
				results.Add(CreateAttribute("patientBirthDate", _queryParameters.PatientBirthDate));
			if (!_queryParameters.PatientId.IsEmpty)
				results.Add(CreateAttribute("patientId", _queryParameters.PatientId));
			if (!_queryParameters.PatientName.IsEmpty)
				results.Add(CreateAttribute("patientName", _queryParameters.PatientName));
			if (!_queryParameters.PatientSex.IsEmpty)
				results.Add(CreateAttribute("patientSex", _queryParameters.PatientSex));
			if (results.Count > 0)
				obj = (object[])results.ToArray(typeof(object));
			if (obj != null)
			{
				var patientGroup = CreateQRAttrAssoGroup.createGroup(obj, LogicalOperator.AND);
				assoPatient = CreateQRAttrAssoGroup.createAssociation("gov.nih.nci.ncia.domain.Patient", "patient", patientGroup);
			}
			obj = null;
			assoStudy = null;
			results = new ArrayList();
			if (assoPatient != null)
				results.Add(assoPatient);
			if (!_queryParameters.StudyInstanceUID.IsEmpty)
				results.Add(CreateAttribute("studyInstanceUID", _queryParameters.StudyInstanceUID));
			if (results.Count > 0)
				obj = (object[])results.ToArray(typeof(object));
			if (obj != null)
			{
				var grpStudy = CreateQRAttrAssoGroup.createGroup(obj, LogicalOperator.AND);
				assoStudy = CreateQRAttrAssoGroup.createAssociation("gov.nih.nci.ncia.domain.Study", "study", grpStudy);
			}
			assoImage = null;
			if (!_queryParameters.SliceThickness.IsEmpty)
			{
				var attrPatient = CreateAttribute("sliceThickness", _queryParameters.SliceThickness);
				var grpPatient = CreateQRAttrAssoGroup.createGroup(attrPatient, LogicalOperator.AND);
				assoImage = CreateQRAttrAssoGroup.createAssociation("gov.nih.nci.ncia.domain.Image", "imageCollection", grpPatient);
			}
			obj = null;
			Group grpSeries = null;
			results = new ArrayList();
			if (assoImage != null)
				results.Add(assoImage);
			if (assoStudy != null)
				results.Add(assoStudy);
			if (!_queryParameters.Modality.IsEmpty)
				results.Add(CreateAttribute("modality", _queryParameters.Modality));
			if (results.Count > 0)
				obj = (object[])results.ToArray(typeof(object));
			if (obj != null)
				grpSeries = CreateQRAttrAssoGroup.createGroup(obj, LogicalOperator.AND);

			var arg = CreateQRAttrAssoGroup.createQueryRequestCqlQuery("gov.nih.nci.ncia.domain.Series", items, itemsChoiceType1, null, grpSeries);
			var doc = XMLSerializingDeserializing.Serialize(arg);
			Console.WriteLine(doc.InnerXml);
			try
			{
				result = proxy.query(arg);
			}
			catch (System.Net.WebException ex)
			{
				Console.WriteLine(ex.Message);
				result = null;
			}
			catch (Exception e)
			{
				Console.WriteLine(e.Message);
				result = null;
				throw new GridServicerException("Error querying NCIA Grid", e);
			}
			return result;
		}
	}
}