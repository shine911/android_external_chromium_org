// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_RENDERER_PEPPER_URL_REQUEST_INFO_UTIL_H_
#define CONTENT_RENDERER_PEPPER_URL_REQUEST_INFO_UTIL_H_

#include "base/memory/ref_counted.h"
#include "content/common/content_export.h"

namespace ppapi {
struct URLRequestInfoData;
}

namespace WebKit {
class WebFrame;
class WebURLRequest;
}

namespace webkit {
namespace ppapi {

// Creates the WebKit URL request from the current request info. Returns true
// on success, false if the request is invalid (in which case *dest may be
// partially initialized). Any upload files with only resource IDs (no file ref
// pointers) will be populated by this function on success.
CONTENT_EXPORT bool CreateWebURLRequest(::ppapi::URLRequestInfoData* data,
                                        WebKit::WebFrame* frame,
                                        WebKit::WebURLRequest* dest);

// Returns true if universal access is required to use the given request.
CONTENT_EXPORT bool URLRequestRequiresUniversalAccess(
    const ::ppapi::URLRequestInfoData& data);

}  // namespace ppapi
}  // namespace webkit

#endif  // CONTENT_RENDERER_PEPPER_PPB_URL_REQUEST_INFO_UTIL_H_