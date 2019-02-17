#include "gettwoform.h"

TwoForm* GetTwoForm::form = NULL;
GetTwoForm::GetTwoForm()
{

}
TwoForm* GetTwoForm::getobject(void)
{
    if(form == NULL)
        form = new TwoForm();
    return form;
}
