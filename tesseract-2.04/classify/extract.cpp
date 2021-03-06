/******************************************************************************
 **	Filename:    extract.c
 **	Purpose:     Generic high level feature extractor routines.
 **	Author:      Dan Johnson
 **	History:     Sun Jan 21 09:44:08 1990, DSJ, Created.
 **
 **	(c) Copyright Hewlett-Packard Company, 1988.
 ** Licensed under the Apache License, Version 2.0 (the "License");
 ** you may not use this file except in compliance with the License.
 ** You may obtain a copy of the License at
 ** http://www.apache.org/licenses/LICENSE-2.0
 ** Unless required by applicable law or agreed to in writing, software
 ** distributed under the License is distributed on an "AS IS" BASIS,
 ** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 ** See the License for the specific language governing permissions and
 ** limitations under the License.
 ******************************************************************************/
/**----------------------------------------------------------------------------
          Include Files and Type Defines
----------------------------------------------------------------------------**/
#include "extract.h"
#include "variables.h"
#include "flexfx.h"
#include "funcdefs.h"
#include "danerror.h"

typedef CHAR_FEATURES (*CF_FUNC) ();

/**----------------------------------------------------------------------------
          Private Function Prototypes
----------------------------------------------------------------------------**/
void ExtractorStub(); 

/**----------------------------------------------------------------------------
        Global Data Definitions and Declarations
----------------------------------------------------------------------------**/
/* tables to keep track of the different low level feature extractors */
#define NUM_FX        3
#define DEFAULT_FX      2

int CurrentFx = DEFAULT_FX;

/**----------------------------------------------------------------------------
              Public Code
----------------------------------------------------------------------------**/
/*---------------------------------------------------------------------------*/
CHAR_DESC ExtractBlobFeatures(TBLOB *Blob, LINE_STATS *LineStats) { 
/*
 **	Parameters:
 **		Blob		blob to extract features from
 **		LineStats	statistics about line blob is in
 **	Operation: Extract features from Blob by calling the feature
 **		extractor which is currently being used.  This routine
 **		simply provides a high level interface to feature
 **		extraction.  The caller can extract any type of features
 **		from a blob without understanding any lower level details.
 **	Return: The character features extracted from Blob.
 **	Exceptions: none
 **	History: Sun Jan 21 10:07:28 1990, DSJ, Created.
 */
  return (ExtractFlexFeatures (Blob, LineStats));
}                                /* ExtractBlobFeatures */


/*---------------------------------------------------------------------------*/
void InitExtractorVars() { 
/*
 **	Parameters: none
 **	Globals: none
 **	Operation: Install global extractor variables into the variable
 **		system.
 **	Return: none
 **	Exceptions: none
 **	History: Sun Jan 21 10:19:59 1990, DSJ, Created.
 */
  //      VALUE dummy;
  InitFlexFXVars(); 

}                                /* InitExtractorVars */


/**----------------------------------------------------------------------------
              Private Code
----------------------------------------------------------------------------**/
/*---------------------------------------------------------------------------*/
void
ExtractorStub ()
/*
 **	Parameters: none
 **	Globals: none
 **	Operation: This routine is used to stub out feature extractors
 **		that are no longer used.  It simply calls DoError.
 **	Return: none
 **	Exceptions: none
 **	History: Wed Jan  2 14:16:49 1991, DSJ, Created.
 */
#define DUMMY_ERROR     1
{
  DoError (DUMMY_ERROR, "Selected feature extractor has been stubbed out!");
}                                /* ExtractorStub */
