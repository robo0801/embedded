#include <StepperMotor.h>
StepperMotor stepper(8, 9, 10, 11);

void setup() {
  stepper.setPeriod(1); 
}
void loop() {
      stepper.move(4096);
      stepper.stop();
      delay(500);
      stepper.move(-4096);
      stepper.stop();
      delay(500);
}
