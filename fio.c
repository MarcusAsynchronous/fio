/*
 * fio - the flexible io tester
 *
 * Copyright (C) 2005 Jens Axboe <axboe@suse.de>
 * Copyright (C) 2006-2012 Jens Axboe <axboe@kernel.dk>
 *
 * The license below covers all files distributed with fio unless otherwise
 * noted in the file itself.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
#include <unistd.h>
#include <locale.h>
#include <time.h>

#include "fio.h"
#include "hash.h"
#include "smalloc.h"
#include "verify.h"
#include "trim.h"
#include "diskutil.h"
#include "profile.h"
#include "lib/rand.h"
#include "memalign.h"
#include "client.h"
#include "server.h"

int main(int argc, char *argv[], char *envp[])
{
	if (initialize_fio(envp))
		return 1;

	if (parse_options(argc, argv))
		return 1;

	if (nr_clients)
		return fio_handle_clients(&fio_client_ops);
	else
		return fio_backend();
}
