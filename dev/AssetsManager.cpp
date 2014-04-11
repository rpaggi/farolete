#include "AssetsManager.hpp"

template <typename Asset, typename Identifier>
void AssetsManager<Asset, Identifier>::load(Identifier id, const std::string& filename)
{
    // Create and load resource
	std::unique_ptr<Asset> asset(new Asset());
	if (!asset->loadFromFile(filename))
		throw std::runtime_error("AssetManager::load - Failed to load " + filename);

	// If loading successful, insert resource to map
	insertAsset(id, std::move(asset));
}

template <typename Asset, typename Identifier>
Asset& AssetsManager<Asset, Identifier>::get(Identifier id){

	auto found = mAssetMap.find(id);
	assert(found != mAssetMap.end());

	return *found->second;
}

template <typename Asset, typename Identifier>
const Asset& AssetsManager<Asset, Identifier>::get(Identifier id) const{

	auto found = mAssetMap.find(id);
	assert(found != mAssetMap.end());

	return *found->second;
}

template <typename Asset, typename Identifier>
void AssetsManager<Asset, Identifier>::insertAsset(Identifier id, std::unique_ptr<Asset> asset) 
{
	// Insert and check success
	auto inserted = mAssetMap.insert(std::make_pair(id, std::move(asset)));
	assert(inserted.second);
}