//
// Created by dex on 3/13/22.
//

#ifndef OPENGLPROJECT_TESTMODEL_H
#define OPENGLPROJECT_TESTMODEL_H
#include"test.h"
namespace test {
    class TestModel : public test {
    public:
        void OnUpdate(float DateTime) override;

        void OnRender() override;

        void OnImGuiRender() override;


    };
}


#endif //OPENGLPROJECT_TESTMODEL_H
