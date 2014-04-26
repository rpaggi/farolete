#ifndef ASSETSMANAGER_HPP
#define ASSETSMANAGER_HPP

#include <string>
#include <map>
#include <memory>
#include <cassert>

template <typename Asset, typename Identifier>
class AssetsManager
{
    public:
        void           load(Identifier id,const std::string& filename);

        Asset&         get(Identifier id);
        const Asset&   get(Identifier id) const;

    private:
   		void		   insertAsset(Identifier id, std::unique_ptr<Asset> asset);

        std::map<Identifier,std::unique_ptr<Asset>> mAssetMap;
};

#endif