#include "getthreeform.h"

ThreeForm* GetThreeForm::form = NULL;

GetThreeForm::GetThreeForm()
{

}
ThreeForm* GetThreeForm::getobject(void)
{
    if(form == NULL)
        form = new ThreeForm();
    return form;
}
