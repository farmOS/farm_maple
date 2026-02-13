<?php

namespace Drupal\farm_maple\Plugin\Asset\AssetType;

use Drupal\Core\StringTranslation\TranslatableMarkup;
use Drupal\farm_entity\Attribute\AssetType;
use Drupal\farm_entity\Plugin\Asset\AssetType\FarmAssetType;

/**
 * Provides the maple asset type.
 */
#[AssetType(
  id: 'maple',
  label: new TranslatableMarkup('Maple'),
)]
class Maple extends FarmAssetType {

}
