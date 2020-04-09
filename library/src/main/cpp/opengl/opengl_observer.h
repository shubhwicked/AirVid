/*
* Copyright (C) 2020 Mobisoft. All rights reserved.
 * Copyright (C) 2020 Shubham Kamlapuri <shubhwicked@gmail.com>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

//
//  opengl_observer.h
//  opengl
//
//  Created by Shubham on 2020/8/30.
//  Copyright © 2020 com.Shubham.opengl. All rights reserved.
//

#ifndef opengl_observer_h
#define opengl_observer_h

namespace mobisoft {

class OnGLObserver {
 public:
    virtual void OnGLParams() = 0;
    virtual void OnGLArrays() = 0;
};    
    
}

#endif /* opengl_observer_h */
