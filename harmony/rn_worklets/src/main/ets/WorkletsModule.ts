import { TurboModule } from '@rnoh/react-native-openharmony/ts';
import Logger from './Logger';

export class WorkletsModule extends TurboModule {
  constructor(ctx) {
    super(ctx);
    Logger.debug('[RNOH]:WorkletsModule TurboModule constructor');
  }
}