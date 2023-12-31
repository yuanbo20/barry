/*====================================================================*
 *
 *   Copyright (c) 2013 Qualcomm Atheros, Inc.
 *
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted (subject to the limitations
 *   in the disclaimer below) provided that the following conditions
 *   are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials
 *     provided with the distribution.
 *
 *   * Neither the name of Qualcomm Atheros nor the names of
 *     its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written
 *     permission.
 *
 *   NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
 *   GRANTED BY THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE
 *   COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 *   IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *   PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 *   OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 *   NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 *   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *--------------------------------------------------------------------*/
/*====================================================================*
 *
 *   signed HomePlugHeader1 (struct homeplug_fmi * header, uint8_t MMV, uint16_t MMTYPE);
 *
 *   mme.h
 *
 *   encode memory with a standard HomePlug AV header having HomePlug
 *   protocol version (HOMEPLUG_MMV) and HomePlug message type (MMTYPE);
 *   return the number of bytes actually encoded;
 *
 *
 *   Contributor(s):
 *  Charles Maier
 *
 *--------------------------------------------------------------------*/
#ifndef HOMEPLUGHEADER1_SOURCE
#define HOMEPLUGHEADER1_SOURCE
#include <stdint.h>
#include "../mme/mme.h"
#include "../tools/slac_endian.h"
signed HomePlugHeader1 (struct homeplug_fmi * header, uint8_t MMV, uint16_t MMTYPE)
{
  header->MMV = MMV;
  header->MMTYPE = HTOLE16 (MMTYPE);
  header->FMSN = 0;
  header->FMID = 0;
  return (sizeof (* header));
}
#endif
