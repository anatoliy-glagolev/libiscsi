/* 
   Copyright (C) 2013 Ronnie Sahlberg <ronniesahlberg@gmail.com>
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <CUnit/CUnit.h>

#include "iscsi.h"
#include "scsi-lowlevel.h"
#include "iscsi-test-cu.h"

void
test_prefetch16_flags(void)
{ 
	int ret;

	logging(LOG_VERBOSE, "");
	logging(LOG_VERBOSE, "Test PREFETCH16 flags");

	logging(LOG_VERBOSE, "Test PREFETCH16 with IMMED==1");
	ret = prefetch16(iscsic, tgt_lun, 0,
			 1, 1, 0);
	CU_ASSERT_EQUAL(ret, 0);

	logging(LOG_VERBOSE, "Test PREFETCH16 with GROUP==3");
	ret = prefetch16(iscsic, tgt_lun, 0,
			 1, 0, 3);
	CU_ASSERT_EQUAL(ret, 0);

	logging(LOG_VERBOSE, "Test PREFETCH16 with IMMED=1 and GROUP==3");
	ret = prefetch16(iscsic, tgt_lun, 0,
			 1, 1, 3);
	CU_ASSERT_EQUAL(ret, 0);
}