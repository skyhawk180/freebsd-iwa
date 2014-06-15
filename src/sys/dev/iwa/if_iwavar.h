
/*-
 * Copyright (c) 2014 Adrian Chadd<adrian@FreeBSD.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
/* $FreeBSD$ */

struct iwa_vap {
	struct ieee80211vap	iv_vap;
};
#define	IWA_VAP(_vap)	((struct iwa_vap *)(_vap))

struct iwa_softc {
	device_t		sc_dev;

	struct ifnet		*sc_ifp;
	int			sc_debug;

	struct mtx		sc_mtx;

	uint8_t 		hw_type;
	/* subdevice_id used to adjust configuration */
	uint16_t		subdevice_id;

	const char		*fwname;

	/* Taskqueue */
	struct taskqueue	*sc_tq;

};

#define IWA_LOCK_INIT(_sc) \
	mtx_init(&(_sc)->sc_mtx, device_get_nameunit((_sc)->sc_dev), \
	    MTX_NETWORK_LOCK, MTX_DEF)
#define IWA_LOCK(_sc)			mtx_lock(&(_sc)->sc_mtx)
#define IWA_LOCK_ASSERT(_sc)		mtx_assert(&(_sc)->sc_mtx, MA_OWNED)
#define IWA_UNLOCK(_sc)			mtx_unlock(&(_sc)->sc_mtx)
#define IWA_LOCK_DESTROY(_sc)		mtx_destroy(&(_sc)->sc_mtx)
