//
//  DTTCustomAnimations.h
//  Animation
//
//  Created by Shaurya on 20/06/15.
//  Copyright (c) 2015 DigitalThinkrz. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DTTCustomAnimations : NSObject
/*
 * A super handy single method for making any custom animation for one time or multiple times.
 * It will also work even when you are going to background state of app you don't need to handle it seprately.
 *
 * @params
 *  animateView           - Your custom view which you want to animate.
 *  startValue/endValue   - It can be NULL or any NSValue or any NSNumber.
                            For e.g -
                            NSNumber numberWithFloat:<#(float)#>
                            NSValue valueWithCATransform3D:<#(CATransform3D)#>
                            NSValue valueWithCGAffineTransform:<#(CGAffineTransform)#>
 *  name                  - For providing smotheness to view. CAMediaTimingFunction functionWithName:
                            For e.g - These below mentioned values can be passed as param.
                            kCAMediaTimingFunctionLinear
                            kCAMediaTimingFunctionEaseIn
                            kCAMediaTimingFunctionEaseOut
                            kCAMediaTimingFunctionEaseInEaseOut
                            kCAMediaTimingFunctionDefault.
 *  duration              - It is the duration for one cycle of animation.
 *  keyPath               - It's the thing which decide the animation path value - animationWithKeyPath.
                            For e.g- you can give values to param like @"rotation" or @"translation" or @"scale" or @"transform" or @"rotation.x" or @"rotation.y" or @"rotation.z" - similar for others also.
 *  isAutoreverses        - It provides the same vice-versa functionality.
                            For e.g- You went 10px forward if you again want to reach your original position you can reach just by setting its value true.
 *  repeatCount           - It is the total number of times you want to show the animation.
                            For e.g- 1,2, 10, 100 or INFINITY (for continuous animation)
 *
 *
 */
+ (void)defaultCustomizedAnimationForView:(UIView *)animateView
                        fromStartingValue:(id)startValue
                            toEndingValue:(id)endValue
              withMediaTimingFunctionName:(NSString *)name
                      inAnimationDuration:(CFTimeInterval)duration
                               forKeyPath:(NSString *)keyPath
                   withAutoreverseAbility:(BOOL)isAutoreverses
                     andTotalRepeatCounts:(float)repeatCount;

/*
 *
 *
 * From Apple Docs Anchor Point Definition
 - You specify the value for this property using the unit coordinate space. The default value of this property is (0.5, 0.5), which represents the center of the layer’s bounds rectangle. All geometric manipulations to the view occur about the specified point. For example, applying a rotation transform to a layer with the default anchor point causes the layer to rotate around its center. Changing the anchor point to a different location would cause the layer to rotate around that new point.
 *
 *
 * In simple terms it is the point which needs to be fixed for animation purpose.
 * You can use any anchor point before adding custom animation to the view. Sometimes apple default method of setting anchor point will not work properly of setting anchor point as it depends on outer view.
 *
 *
 */
+ (void)setAnchorPoint:(CGPoint)anchorPoint forAnyView:(UIView *)view;
@end
