import type {RNPackageContext, RNPackage} from '@rnoh/react-native-openharmony/ts';
import { WorkletsPackage } from "@react-native-oh-tpl/react-native-worklets-core/ts";

export function createRNPackages(ctx: RNPackageContext): RNPackage[] {
  return [
    new WorkletsPackage(ctx),
  ];
}
