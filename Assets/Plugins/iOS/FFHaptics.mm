// Haptic taps for Furniture Factory (FF.Gameplay.Audio.Haptics): style 0 = light, 1 = medium.
#import <UIKit/UIKit.h>

extern "C" void FFHapticImpact(int style)
{
    dispatch_async(dispatch_get_main_queue(), ^{
        UIImpactFeedbackStyle s = style == 0 ? UIImpactFeedbackStyleLight : UIImpactFeedbackStyleMedium;
        UIImpactFeedbackGenerator *generator = [[UIImpactFeedbackGenerator alloc] initWithStyle:s];
        [generator prepare];
        [generator impactOccurred];
    });
}
