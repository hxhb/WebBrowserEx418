
#include "WebBrowserExWidget.h"
#include "SWebBrowser.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Application/SlateApplication.h"

#define LOCTEXT_NAMESPACE "WebBrowserEx"

UWebBrowserExWidget::UWebBrowserExWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

TSharedRef<SWidget> UWebBrowserExWidget::RebuildWidget()
{
	if (IsDesignTime())
	{
		return SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("Web Browser", "Web Browser"))
			];
	}
	else
	{
		WebBrowserWidget = SNew(SWebBrowser)
			.InitialURL(InitialURL)
			.ShowControls(false)
			.SupportsTransparency(bSupportsTransparency)
			.OnUrlChanged(BIND_UOBJECT_DELEGATE(FOnTextChanged, HandleOnUrlChanged));
		// support chinese input
		if (WebBrowserWidget.IsValid())
		{
			class ITextInputMethodSystem* const TextInputMethodSystem = FSlateApplication::Get().GetTextInputMethodSystem();
			WebBrowserWidget->BindInputMethodSystem(TextInputMethodSystem);
		}

		return WebBrowserWidget.ToSharedRef();
	}

}

#undef LOCTEXT_NAMESPACE