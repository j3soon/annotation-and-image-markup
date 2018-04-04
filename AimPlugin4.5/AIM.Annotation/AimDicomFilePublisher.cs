﻿#region License

// Copyright (c) 2007 - 2014, Northwestern University, Vladimir Kleper, Skip Talbot
// and Pattanasak Mongkolwat.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
//   Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
//   Neither the name of the National Cancer Institute nor Northwestern University
//   nor the names of its contributors may be used to endorse or promote products
//   derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#endregion

using System;
using System.Collections.Generic;
using ClearCanvas.Common;
using ClearCanvas.Dicom;
using ClearCanvas.Dicom.Audit;
using ClearCanvas.Dicom.Network;
using ClearCanvas.ImageViewer.Common.StudyManagement;
using ClearCanvas.ImageViewer.Common.WorkItem;
using ClearCanvas.ImageViewer.StudyManagement.Core;

namespace AIM.Annotation
{
	public static class AimDicomFilePublisher
	{
		// Essentially this is a copy of ClearCanvas.ImageViewer.StudyManagement.Core.DicomFilePublisher that allows us to move files 
		// instead of leaving them orphaned in the original folder.
		// TODO: revisit this when ClearCanvas.ImageViewer.StudyManagement.Core.DicomFilePublisher gets an option for moving files
		public static void PublishLocal(ICollection<DicomFile> files)
		{
			if (files == null || files.Count == 0)
				return;

			var configuration = ClearCanvas.ImageViewer.Common.DicomServer.DicomServer.GetConfiguration();
			var context = new ImportStudyContext(configuration.AETitle, StudyStore.GetConfiguration(), EventSource.CurrentUser);

			var utility = new ImportFilesUtility(context);

			try
			{
				DicomProcessingResult failureResult = null;

				foreach (var file in files)
				{
					var importResult = utility.Import(file, BadFileBehaviourEnum.Move, FileImportBehaviourEnum.Move); // THIS IS THE CHANGE
					if (importResult.DicomStatus != DicomStatuses.Success)
					{
						Platform.Log(LogLevel.Warn, "Unable to import published file: {0}", importResult.ErrorMessage);
						failureResult = importResult;
					}
				}

				if (failureResult != null)
					throw new ApplicationException(failureResult.ErrorMessage);
			}
			catch (Exception ex)
			{
				var message = String.Format("Failed to import files");
				throw new Exception(message, ex);
			}
		}
	}
}