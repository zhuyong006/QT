#ifndef GETONEFORM_H
#define GETONEFORM_H
#include "oneform.h"


class GetOneForm
{
public:
    GetOneForm();
    static OneForm* getobject(void);
    static OneForm* form;
};

#endif // GETONEFORM_H
