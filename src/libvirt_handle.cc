#include <libvirt/libvirt.h>
#include "libvirt_handle.h"

namespace NodeLibvirt {

class LibVirtHandlePrivate
{
public:
  LibVirtHandlePrivate() {
    data.connection = 0;
    data.interface = 0;
    data.network = 0;
    data.networkFilter = 0;
    data.storagePool = 0;
    data.storageVolume = 0;
    data.nodeDevice = 0;
    data.secret = 0;
    data.domain = 0;
  }

  ~LibVirtHandlePrivate() {
    Clear();
  }

  void Clear() {
    data.connection = 0;

    if (data.interface)
      virInterfaceFree(data.interface);
    data.interface = 0;

    if (data.network)
      virNetworkFree(data.network);
    data.network = 0;

    if (data.networkFilter)
      virNWFilterFree(data.networkFilter);
    data.networkFilter = 0;

    if (data.storagePool)
      virStoragePoolFree(data.storagePool);
    data.storagePool = 0;

    if (data.storageVolume)
      virStorageVolFree(data.storageVolume);
    data.storageVolume = 0;

    if (data.nodeDevice)
      virNodeDeviceFree(data.nodeDevice);
    data.nodeDevice = 0;

    if (data.secret)
      virSecretFree(data.secret);
    data.secret = 0;

    if (data.domain)
      virDomainFree(data.domain);
    data.domain = 0;
  }

  union Data {
    virConnectPtr connection;
    virInterfacePtr interface;
    virNetworkPtr network;
    virNWFilterPtr networkFilter;
    virStoragePoolPtr storagePool;
    virStorageVolPtr storageVolume;
    virNodeDevicePtr nodeDevice;
    virSecretPtr secret;
    virDomainPtr domain;
  } data;
};

LibVirtHandle::LibVirtHandle()
  : d(new LibVirtHandlePrivate)
{
}

LibVirtHandle::LibVirtHandle(virConnectPtr connection)
  : d(new LibVirtHandlePrivate)
{
  d->data.connection = connection;
}

LibVirtHandle::LibVirtHandle(virInterfacePtr interface)
  : d(new LibVirtHandlePrivate)
{
  d->data.interface = interface;
}

LibVirtHandle::LibVirtHandle(virNetworkPtr network)
  : d(new LibVirtHandlePrivate)
{
  d->data.network = network;
}

LibVirtHandle::LibVirtHandle(virNWFilterPtr networkFilter)
  : d(new LibVirtHandlePrivate)
{
  d->data.networkFilter = networkFilter;
}

LibVirtHandle::LibVirtHandle(virStoragePoolPtr storagePool)
  : d(new LibVirtHandlePrivate)
{
  d->data.storagePool = storagePool;
}

LibVirtHandle::LibVirtHandle(virStorageVolPtr storageVolume)
  : d(new LibVirtHandlePrivate)
{
  d->data.storageVolume = storageVolume;
}

LibVirtHandle::LibVirtHandle(virNodeDevicePtr nodeDevice)
  : d(new LibVirtHandlePrivate)
{
  d->data.nodeDevice = nodeDevice;
}

LibVirtHandle::LibVirtHandle(virSecretPtr secret)
  : d(new LibVirtHandlePrivate)
{
  d->data.secret = secret;
}

LibVirtHandle::LibVirtHandle(virDomainPtr domain)
  : d(new LibVirtHandlePrivate)
{
  d->data.domain = domain;
}

void LibVirtHandle::Clear()
{
  d->Clear();
}

virConnectPtr LibVirtHandle::ToConnection() const
{
  return d->data.connection;
}

virInterfacePtr LibVirtHandle::ToInterface() const
{
  return d->data.interface;
}

virNetworkPtr LibVirtHandle::ToNetwork() const
{
  return d->data.network;
}

virNWFilterPtr LibVirtHandle::ToNetworkFilter() const
{
  return d->data.networkFilter;
}

virStoragePoolPtr LibVirtHandle::ToStoragePool() const
{
  return d->data.storagePool;
}

virStorageVolPtr LibVirtHandle::ToStorageVolume() const
{
  return d->data.storageVolume;
}

virNodeDevicePtr LibVirtHandle::ToNodeDevice() const
{
  return d->data.nodeDevice;
}

virSecretPtr LibVirtHandle::ToSecret() const
{
  return d->data.secret;
}

virDomainPtr LibVirtHandle::ToDomain() const
{
  return d->data.domain;
}

} // namespace NodeLibvirt
