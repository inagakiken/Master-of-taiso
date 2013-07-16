/* ----------------------------------------------------------------- */
/*                                                                   */
/*  Copyright (c) 2010-2013  hkrn                                    */
/*                                                                   */
/* All rights reserved.                                              */
/*                                                                   */
/* Redistribution and use in source and binary forms, with or        */
/* without modification, are permitted provided that the following   */
/* conditions are met:                                               */
/*                                                                   */
/* - Redistributions of source code must retain the above copyright  */
/*   notice, this list of conditions and the following disclaimer.   */
/* - Redistributions in binary form must reproduce the above         */
/*   copyright notice, this list of conditions and the following     */
/*   disclaimer in the documentation and/or other materials provided */
/*   with the distribution.                                          */
/* - Neither the name of the MMDAI project team nor the names of     */
/*   its contributors may be used to endorse or promote products     */
/*   derived from this software without specific prior written       */
/*   permission.                                                     */
/*                                                                   */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND            */
/* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,       */
/* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF          */
/* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE          */
/* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS */
/* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,          */
/* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED   */
/* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     */
/* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON */
/* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,   */
/* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY    */
/* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE           */
/* POSSIBILITY OF SUCH DAMAGE.                                       */
/* ----------------------------------------------------------------- */

#include "vpvl2/extensions/osx/ql4pmx/Context.h"
#include "vpvl2/extensions/Pose.h"

#include <Cocoa/Cocoa.h>

#include <string>
#include <sstream>

using namespace vpvl2::extensions;
using namespace vpvl2::extensions::icu4c;
using namespace vpvl2::extensions::osx::ql4pmx;

int main(int argc, char *argv[])
{
    if (argc > 1) {
        BundleContext::initialize();
        @autoreleasepool {
            CGContextRef bitmapContext = 0;
            CGImageRef cgImage = 0;
            try {
                CFBundleRef mainBundle = CFBundleGetMainBundle();
                BundleContext context(mainBundle, 640, 480, 1);
                Pose pose(context.encodingRef());
                if (argc > 2) {
                    NSError *error = nil;
                    NSString *path = [NSString stringWithUTF8String:argv[2]];
                    NSString *data = [NSString stringWithContentsOfFile:path
                                                               encoding:NSShiftJISStringEncoding
                                                                  error:&error];
                    const char *s = [data UTF8String];
                    std::string str(s);
                    std::istringstream stream(str);
                    pose.load(stream);
                }
                const char *modelPath = argv[1];
                context.load(UnicodeString::fromUTF8(modelPath));
                pose.bind(context.currentModel());
                context.render();
                bitmapContext = context.createBitmapContext();
                cgImage = CGBitmapContextCreateImage(bitmapContext);
                const CGSize &size = context.size();
                NSImage *nsImage = [[NSImage alloc] initWithCGImage:cgImage
                                                                    size:NSMakeSize(size.width, size.height)];
                [[nsImage TIFFRepresentation] writeToFile:@"test.tiff" atomically:YES];
                [nsImage release];
            } catch (std::exception e) {
                NSLog(@"%s", e.what());
            }
            CGImageRelease(cgImage);
            CGContextRelease(bitmapContext);
        }
    }
    return 0;
}
