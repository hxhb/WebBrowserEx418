#pragma once

#include "WebBrowser.h"
#include "Components/Widget.h"

#include "WebBrowserExWidget.generated.h"

UCLASS()
class WEBBROWSEREX_API UWebBrowserExWidget:public UWebBrowser
{
	GENERATED_UCLASS_BODY()

protected:
	virtual TSharedRef<SWidget> RebuildWidget();
};
