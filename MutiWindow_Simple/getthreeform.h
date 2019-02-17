#ifndef GETTHREEFORM_H
#define GETTHREEFORM_H
#include "threeform.h"


class GetThreeForm
{
public:
    GetThreeForm();
    static ThreeForm* getobject(void);
    static ThreeForm* form;
};

#endif // GETTHREEFORM_H
