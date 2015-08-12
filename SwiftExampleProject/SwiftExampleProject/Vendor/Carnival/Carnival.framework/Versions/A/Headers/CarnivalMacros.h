//
//  CarnivalMacros.h
//  Carnival
//
//  Created by Sam Jarman on 14/07/15.
//  Copyright (c) 2015 Carnival Labs . All rights reserved.
//

#ifndef Carnival_CarnivalMacros_h
#define Carnival_CarnivalMacros_h


// Xcode 6.3 defines new language features to declare nullability
#if __has_feature(nullability)
#define carnival_ASSUME_NONNULL_BEGIN _Pragma("clang assume_nonnull begin")
#define carnival_ASSUME_NONNULL_END _Pragma("clang assume_nonnull end")
#define carnival_nullable nullable
#define carnival_nonnull nonnull
#define carnival_null_unspecified null_unspecified
#define carnival_null_resettable null_resettable
#define __carnival_nullable __nullable
#define __carnival_nonnull __nonnull
#define __carnival_null_unspecified __null_unspecified
#else
#define carnival_ASSUME_NONNULL_BEGIN
#define carnival_ASSUME_NONNULL_END
#define carnival_nullable
#define carnival_nonnull
#define carnival_null_unspecified
#define carnival_null_resettable
#define __carnival_nullable
#define __carnival_nonnull
#define __carnival_null_unspecified
#endif

#endif
