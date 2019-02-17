#include "getoneform.h"

OneForm * GetOneForm::form = NULL;
GetOneForm::GetOneForm()
{

}

OneForm * GetOneForm::getobject(void)
{
    if(form == NULL)
        form = new OneForm();
    return form;
}
