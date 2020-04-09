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
// Created by Shubham on 2020/4/2.
//

#ifndef MOBISOFT_MESSAGE_QUEUE_H
#define MOBISOFT_MESSAGE_QUEUE_H

#include <pthread.h>
#define MESSAGE_QUEUE_LOOP_QUIT_FLAG        19900909

namespace mobisoft {

class Handler;

class Message {
 private:
    int what;
    int arg1;
    int arg2;
    int arg3;
    void* obj;

 public:
    Message();
    explicit Message(int what);
    Message(int what, int arg1, int arg2);
    Message(int what, int arg1, int arg2, int arg3);
    Message(int what, int arg1, int arg2, int arg3, void* obj);
    Message(int what, void* obj);
    Message(int what, int arg1, int arg2, void* obj);
    ~Message();

    int Execute();
    int GetWhat() {
        return what;
    }
    int GetArg1() {
        return arg1;
    }
    int GetArg2() {
        return arg2;
    }
    int GetArg3() {
        return arg3;
    }
    void* GetObj() {
        return obj;
    }
    Handler* handler_;
};

typedef struct MessageNode {
    Message *msg;
    struct MessageNode *next;
    MessageNode() {
        msg = NULL;
        next = NULL;
    }
} MessageNode;

class MessageQueue {
 private:
    MessageNode* first_;
    MessageNode* last_;
    int packet_size_;
    bool abort_request_;
    pthread_mutex_t lock_;
    pthread_cond_t condition_;
    const char* queue_name_;

 public:
    MessageQueue();
    explicit MessageQueue(const char* queueNameParam);
    ~MessageQueue();

    void Init();
    void Flush();
    int EnqueueMessage(Message *msg);
    int DequeueMessage(Message **msg, bool block);
    int Size();
    void Abort();
};

}  // namespace mobisoft

#endif  // MOBISOFT_MESSAGE_QUEUE_H
